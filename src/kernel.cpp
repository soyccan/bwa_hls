#include "kernel.h"

#include "utils.h"

static inline bool match_symbol(int i, char c)
{
  return (i == 0 && c == 'A') || (i == 1 && c == 'C') || (i == 2 && c == 'G') ||
         (i == 3 && c == 'T');
}

template <int ID>
static void bwa_align_pe(
    // output: SA intervals
    int res_sa_itv[BUF_SIZE][2], int* res_sa_len,

    // buffer (R/W) for a queue recording states (i,z,k,l)
    // host should guarantee a sufficiently large buffer
    int buf[BUF_SIZE][4],

    const int occ[BUF_SIZE][4],  // size: (ref_len+1) * 4
    const int cum[4],

    int ref_len,

    const char read[READ_MAX_LEN], int read_len)
{
  int head;
  int tail;
  int res_sz;

  static char read_buf[READ_MAX_LEN];
  static int cum_buf[4];

  FOR (i, 0, array_size(read_buf)) {
#pragma HLS UNROLL
    read_buf[i] = read[i];
  }
  FOR (i, 0, array_size(cum_buf)) {
#pragma HLS UNROLL
    cum_buf[i] = cum[i];
  }

  // buf[i][0]: j
  // buf[i][1]: z (#allowed mismatches left)
  // buf[i][2]: k (left bound of SA interval)
  // buf[i][3]: l (right bound of SA interval)
  buf[0][0] = read_len - 1;
  buf[0][1] = MAX_MISMATCH;
  buf[0][2] = 0;
  buf[0][3] = ref_len;

  int i, z, k, l;
  res_sz = 0;
LOOP_OUTER:
  for (head = 0, tail = 1; head < tail; head++) {
    // clang-format off
#pragma HLS PIPELINE
#pragma HLS DEPENDENCE variable=buf intra WAR false
#pragma HLS DEPENDENCE variable=buf inter WAW false
    // clang-format on
    i = buf[head][0];
    z = buf[head][1];
    k = buf[head][2];
    l = buf[head][3];

    if (i < 0) {
      res_sa_itv[res_sz][0] = k;
      res_sa_itv[res_sz][1] = l;
      res_sz++;
      continue;
    }
    if (z < 0) {
      // TODO: determine lower bound
      continue;
    }

    debug("head=%d tail=%d i=%d z=%d k=%d l=%d", head, tail, i, z, k, l);

    // insert
    buf[tail][0] = i - 1;
    buf[tail][1] = z - 1;
    buf[tail][2] = k;
    buf[tail][3] = l;
    debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail][0], buf[tail][1],
          buf[tail][2], buf[tail][3]);

  LOOP_INNER:
    for (int s = 0; s < 4; s++) {
#pragma HLS UNROLL
      int o = 0;
      if (k > 0)
        o = occ[k - 1][s];
      int k_nxt = cum_buf[s] + o;
      int l_nxt = cum_buf[s] + occ[l][s] - 1;

      if (k_nxt <= l_nxt) {
        // SNP (substitute) alpha[s]
        buf[tail + 2 * s + 1][0] = i;
        buf[tail + 2 * s + 1][1] = z - 1;
        buf[tail + 2 * s + 1][2] = k_nxt;
        buf[tail + 2 * s + 1][3] = l_nxt;

        if (match_symbol(s, read_buf[i])) {
          // match alpha[s]
          buf[tail + 2 * s + 2][0] = i - 1;
          buf[tail + 2 * s + 2][1] = z;
          buf[tail + 2 * s + 2][2] = k_nxt;
          buf[tail + 2 * s + 2][3] = l_nxt;
        }
        else {
          // delete alpha[s]
          buf[tail + 2 * s + 2][0] = i - 1;
          buf[tail + 2 * s + 2][1] = z - 1;
          buf[tail + 2 * s + 2][2] = k_nxt;
          buf[tail + 2 * s + 2][3] = l_nxt;
        }
      }
      else {
        // nop (bubble)
        buf[tail + 2 * s + 1][0] = 0;
        buf[tail + 2 * s + 1][1] = -1;
        buf[tail + 2 * s + 1][2] = 0;
        buf[tail + 2 * s + 1][3] = 0;

        buf[tail + 2 * s + 2][0] = 0;
        buf[tail + 2 * s + 2][1] = -1;
        buf[tail + 2 * s + 2][2] = 0;
        buf[tail + 2 * s + 2][3] = 0;
      }
      debug("tail=%d i=%d z=%d k=%d l=%d", tail + 2 * s + 1,
            buf[tail + 2 * s + 1][0], buf[tail + 2 * s + 1][1],
            buf[tail + 2 * s + 1][2], buf[tail + 2 * s + 1][3]);
      debug("tail=%d i=%d z=%d k=%d l=%d", tail + 2 * s + 2,
            buf[tail + 2 * s + 2][0], buf[tail + 2 * s + 2][1],
            buf[tail + 2 * s + 2][2], buf[tail + 2 * s + 2][3]);
    }
    tail += 9;
  }
  *res_sa_len = res_sz;
}

extern "C" {
void bwa_align(
    // output: SA intervals
    int res_sa_itv[NUM_PE][BUF_SIZE][2],

    // buffer (R/W) for a queue recording states (i,z,k,l)
    // host should guarantee a sufficiently large buffer
    int buf[NUM_PE][BUF_SIZE][4],

    const int occ[BUF_SIZE][4],  // size: (ref_len+1) * 4
    const int cum[4],

    int ref_len,

    const char reads[READ_QUEUE_LEN][READ_MAX_LEN], int readn,
    int res_sa_len[NUM_PE], const int read_len[READ_QUEUE_LEN])
{
  // clang-format off
#pragma HLS INTERFACE s_axilite port=res_sa_itv bundle=control
#pragma HLS INTERFACE s_axilite port=buf bundle=control
#pragma HLS INTERFACE s_axilite port=occ bundle=control
#pragma HLS INTERFACE s_axilite port=cum bundle=control
#pragma HLS INTERFACE s_axilite port=ref_len bundle=control
#pragma HLS INTERFACE s_axilite port=reads bundle=control
#pragma HLS INTERFACE s_axilite port=readn bundle=control
#pragma HLS INTERFACE s_axilite port=res_sa_len bundle=control
#pragma HLS INTERFACE s_axilite port=read_len bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

#pragma HLS INTERFACE m_axi port=res_sa_itv offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=buf offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=occ offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=cum offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=reads offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=res_sa_len offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=read_len offset=slave bundle=gmem

#pragma HLS ARRAY_PARTITION variable=reads complete dim=1
#pragma HLS ARRAY_PARTITION variable=cum complete dim=1
  // clang-format on

  bwa_align_pe<0>(res_sa_itv[0], &res_sa_len[0], buf[0], occ, cum, ref_len,
                  reads[0], read_len[0]);
  bwa_align_pe<1>(res_sa_itv[1], &res_sa_len[1], buf[1], occ, cum, ref_len,
                  reads[1], read_len[1]);
}
}
