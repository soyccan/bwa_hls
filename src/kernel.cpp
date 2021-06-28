#include "kernel.h"

#ifdef __SYNTHESIS__
#include <ap_int.h>
#endif

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

#pragma HLS INTERFACE m_axi port=res_sa_len offset=slave bundle=gmem0
#pragma HLS INTERFACE m_axi port=res_sa_itv offset=slave bundle=gmem0
#pragma HLS INTERFACE m_axi port=buf offset=slave bundle=gmem1
#pragma HLS INTERFACE m_axi port=occ offset=slave bundle=gmem2
#pragma HLS INTERFACE m_axi port=cum offset=slave bundle=gmem3
#pragma HLS INTERFACE m_axi port=read offset=slave bundle=gmem3

#pragma HLS ARRAY_RESHAPE variable=res_sa_itv cyclic factor=2
#pragma HLS ARRAY_RESHAPE variable=buf cyclic factor=4
#pragma HLS ARRAY_RESHAPE variable=occ cyclic factor=4
#pragma HLS ARRAY_RESHAPE variable=cum complete
#pragma HLS ARRAY_RESHAPE variable=read complete
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

  static int buf_r[4];
  static int occ_r[LOCAL_BUF_SIZE][4];
  static int cum_r[4];
  static char read_r[READ_MAX_LEN];

  int occ_off = 0;

  //// read input ////

  FOR (i, 0, LOCAL_BUF_SIZE) {
#pragma HLS UNROLL
    FOR (j, 0, 4) {
      occ_r[i][j] = occ[i * 4 + j];
    }
  }

  FOR (i, 0, array_size(cum_r)) {
#pragma HLS UNROLL
    cum_r[i] = cum[i];
  }

  FOR (i, 0, array_size(read_r)) {
#pragma HLS UNROLL
    read_r[i] = read[i];
  }

  debug("read(%d) = %s", read_len, read);

  //// process ////

  // buf[i][0]: j
  // buf[i][1]: z (#allowed mismatches left)
  // buf[i][2]: k (left bound of SA interval)
  // buf[i][3]: l (right bound of SA interval)
  buf[0] = read_len - 1;
  buf[1] = MAX_MISMATCH;
  buf[2] = 0;
  buf[3] = ref_len;

  int i, z, k, l;
  res_sz = 0;
LOOP_OUTER:
  for (head = 0, tail = 1; head < tail; head++) {
    // clang-format off
// #pragma HLS PIPELINE
#pragma HLS DEPENDENCE variable=buf intra WAR false
#pragma HLS DEPENDENCE variable=buf inter WAW false
    // clang-format on

    FOR (j, 0, 4) {
#pragma HLS UNROLL
      buf_r[j] = buf[head * 4 + j];
    }

    i = buf_r[0];
    z = buf_r[1];
    k = buf_r[2];
    l = buf_r[3];

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
        FOR (i, 0, LOCAL_BUF_SIZE) {
#pragma HLS UNROLL
          FOR (j, 0, 4) {
            occ_r[i][j] = occ[(occ_off * LOCAL_BUF_SIZE + i) * 4 + j];
          }
        }
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

    for (int s = 0; s < 9; s++) {
      for (int t = 0; t < 4; t++) {
#pragma HLS UNROLL
        buf[(tail + s) * 4 + t] = buf_w[s][t];
      }
    }

    tail += 9;
  }

  // write result
  FOR (j, 0, LOCAL_BUF_SIZE) {
#pragma HLS UNROLL
    if (j < tail * 4) {
      res_sa_itv[j * 2] = res_sa_itv_w[j][0];
      res_sa_itv[j * 2 + 1] = res_sa_itv_w[j][1];
    }
  }

  *res_sa_len = res_sz;
}
}
