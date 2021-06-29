#include "kernel.h"

#ifdef __SYNTHESIS__
#include <ap_int.h>
#endif

#include <string.h>

#include "utils.h"

static inline bool match_symbol(int i, char c)
{
  return (i == 0 && c == 'A') || (i == 1 && c == 'C') || (i == 2 && c == 'G') ||
         (i == 3 && c == 'T');
}

extern "C" {
void bwa_align(
    // output: SA intervals
    int* res_sa_len, int res_sa_itv[BUF_SIZE * 2],

    // buffer (R/W) for a queue recording states (i,z,k,l)
    // host should guarantee a sufficiently large buffer
    int buf[BUF_SIZE * 4],

    const int occ[BUF_SIZE * 4],  // size: (ref_len+1) * 4
    const int cum[4],

    int ref_len,

    const char read[READ_MAX_LEN], int read_len)
{
  // clang-format off
#pragma HLS INTERFACE s_axilite port=res_sa_len bundle=control
#pragma HLS INTERFACE s_axilite port=res_sa_itv bundle=control
#pragma HLS INTERFACE s_axilite port=buf bundle=control
#pragma HLS INTERFACE s_axilite port=occ bundle=control
#pragma HLS INTERFACE s_axilite port=cum bundle=control
#pragma HLS INTERFACE s_axilite port=ref_len bundle=control
#pragma HLS INTERFACE s_axilite port=read bundle=control
#pragma HLS INTERFACE s_axilite port=read_len bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

#pragma HLS INTERFACE m_axi port=res_sa_len offset=slave bundle=gmem0 max_write_burst_length=256
#pragma HLS INTERFACE m_axi port=res_sa_itv offset=slave bundle=gmem0 max_write_burst_length=256
#pragma HLS INTERFACE m_axi port=buf offset=slave bundle=gmem1 max_read_burst_length=256 max_write_burst_length=256
#pragma HLS INTERFACE m_axi port=occ offset=slave bundle=gmem2 max_read_burst_length=256
#pragma HLS INTERFACE m_axi port=cum offset=slave bundle=gmem3 max_read_burst_length=256
#pragma HLS INTERFACE m_axi port=read offset=slave bundle=gmem3 max_read_burst_length=256
  // clang-format on

#ifdef __SYNTHESIS__
  ap_uint<LOG2_CEIL<BUF_SIZE>::val> head;
  ap_uint<LOG2_CEIL<BUF_SIZE>::val> tail;
  ap_uint<LOG2_CEIL<BUF_SIZE>::val> res_sz;
#else
  int head;
  int tail;
  int res_sz;
#endif

  static int res_sa_itv_w[LOCAL_BUF_SIZE][2];
  static int buf_w[9][4];

  static int buf_r[LOCAL_BUF_SIZE][4];
  static int occ_r[LOCAL_BUF_SIZE][4];
  static int cum_r[4];
  static char read_r[READ_MAX_LEN];

  int occ_off = 0;
  int buf_r_off = 0;
  int buf_w_off = 0;

  //// read input ////

  memcpy(occ_r, occ, sizeof(occ_r));
  memcpy(cum_r, cum, sizeof(cum_r));
  memcpy(read_r, read, sizeof(read_r));

  debug("read(%d) = %s", read_len, read);

  //// process ////

  // buf[i][0]: j
  // buf[i][1]: z (#allowed mismatches left)
  // buf[i][2]: k (left bound of SA interval)
  // buf[i][3]: l (right bound of SA interval)
  buf_r[0][0] = read_len - 1;
  buf_r[0][1] = MAX_MISMATCH;
  buf_r[0][2] = 0;
  buf_r[0][3] = ref_len;

  int i, z, k, l;
  res_sz = 0;
LOOP_OUTER:
  for (head = 0, tail = 1; head < tail; head++) {
    // clang-format off
// #pragma HLS PIPELINE
#pragma HLS DEPENDENCE variable=buf intra WAR false
#pragma HLS DEPENDENCE variable=buf inter WAW false
    // clang-format on

    if (head >= (buf_r_off + 1) * LOCAL_BUF_SIZE) {
      buf_r_off++;
      memcpy(buf_r, buf + buf_r_off * LOCAL_BUF_SIZE, sizeof(buf_r));
    }

    i = buf_r[head & LOCAL_BUF_SIZE_MASK][0];
    z = buf_r[head & LOCAL_BUF_SIZE_MASK][1];
    k = buf_r[head & LOCAL_BUF_SIZE_MASK][2];
    l = buf_r[head & LOCAL_BUF_SIZE_MASK][3];

    if (i < 0) {
      res_sa_itv_w[res_sz][0] = k;
      res_sa_itv_w[res_sz][1] = l;
      res_sz++;
      continue;
    }
    if (z < 0) {
      // TODO: determine lower bound
      continue;
    }

    debug("head=%d tail=%d i=%d z=%d k=%d l=%d", head, tail, i, z, k, l);

    // insert
    buf_w[0][0] = i - 1;
    buf_w[0][1] = z - 1;
    buf_w[0][2] = k;
    buf_w[0][3] = l;
    debug("tail=%d i=%d z=%d k=%d l=%d", tail + 0, buf_w[0][0], buf_w[0][1],
          buf_w[0][2], buf_w[0][3]);

  LOOP_INNER:
    for (int s = 0; s < 4; s++) {
      // #pragma HLS UNROLL
      int o = 0;
      if (k > 0)
        o = occ_r[(k - 1) % LOCAL_BUF_SIZE][s];
      int k_nxt = cum_r[s] + o;
      int l_nxt = cum_r[s] + occ_r[l % LOCAL_BUF_SIZE][s] - 1;

      if (k_nxt >= (occ_off + 1) * LOCAL_BUF_SIZE) {
        occ_off++;
        memcpy(occ_r, occ + occ_off * LOCAL_BUF_SIZE * 4, sizeof(occ_r));
      }

      if (k_nxt <= l_nxt) {
        // SNP (substitute) alpha[s]
        buf_w[2 * s + 1][0] = i;
        buf_w[2 * s + 1][1] = z - 1;
        buf_w[2 * s + 1][2] = k_nxt;
        buf_w[2 * s + 1][3] = l_nxt;

        if (match_symbol(s, read_r[i])) {
          // match alpha[s]
          buf_w[2 * s + 2][0] = i - 1;
          buf_w[2 * s + 2][1] = z;
          buf_w[2 * s + 2][2] = k_nxt;
          buf_w[2 * s + 2][3] = l_nxt;
        }
        else {
          // delete alpha[s]
          buf_w[2 * s + 2][0] = i - 1;
          buf_w[2 * s + 2][1] = z - 1;
          buf_w[2 * s + 2][2] = k_nxt;
          buf_w[2 * s + 2][3] = l_nxt;
        }
      }
      else {
        // nop (bubble)
        buf_w[2 * s + 1][0] = 0;
        buf_w[2 * s + 1][1] = -1;
        buf_w[2 * s + 1][2] = 0;
        buf_w[2 * s + 1][3] = 0;

        buf_w[2 * s + 2][0] = 0;
        buf_w[2 * s + 2][1] = -1;
        buf_w[2 * s + 2][2] = 0;
        buf_w[2 * s + 2][3] = 0;
      }
      debug("tail=%d i=%d z=%d k=%d l=%d", tail + 2 * s + 1,
            buf_w[2 * s + 1][0], buf_w[2 * s + 1][1], buf_w[2 * s + 1][2],
            buf_w[2 * s + 1][3]);
      debug("tail=%d i=%d z=%d k=%d l=%d", tail + 2 * s + 2,
            buf_w[2 * s + 2][0], buf_w[2 * s + 2][1], buf_w[2 * s + 2][2],
            buf_w[2 * s + 2][3]);
    }

    memcpy(buf + tail * 4, buf_w, sizeof(buf_w));

    tail += 9;
  }

  // write result
  memcpy(res_sa_itv, res_sa_itv_w, res_sz * 2 * sizeof(int));

  *res_sa_len = res_sz;
}
}
