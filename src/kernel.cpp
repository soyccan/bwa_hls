#include "kernel.h"

#include "utils.h"

// Calculates ceil(log2(N_VAL))
// Helpful when calculating #bits needed to index an array with N_VAL
// elements Example:
//     ap_int<LOG2_CEIL<N_REGS>::val> addr;
template <int N_VAL>
struct LOG2_CEIL {
  enum {
    val = N_VAL <= 1     ? 1 :
          N_VAL <= 2     ? 1 :
          N_VAL <= 4     ? 2 :
          N_VAL <= 8     ? 3 :
          N_VAL <= 16    ? 4 :
          N_VAL <= 32    ? 5 :
          N_VAL <= 64    ? 6 :
          N_VAL <= 128   ? 7 :
          N_VAL <= 256   ? 8 :
          N_VAL <= 512   ? 9 :
          N_VAL <= 1024  ? 10 :
          N_VAL <= 2048  ? 11 :
          N_VAL <= 4096  ? 12 :
          N_VAL <= 8192  ? 13 :
          N_VAL <= 16384 ? 14 :
          N_VAL <= 32768 ? 15 :
          N_VAL <= 65536 ? 16 :
                           32
  };
};

static inline bool match_symbol(int i, char c)
{
  return (i == 0 && c == 'A') || (i == 1 && c == 'C') || (i == 2 && c == 'G') ||
         (i == 3 && c == 'T');
}

// static void short_read_buffer() {
//   static char arr[READ_BUF_SIZE];
// }

extern "C" {
void bwa_align(
    int res_sa_itv[BUF_SIZE][2],  // output SA intervals
    int buf[BUF_SIZE][4],  // host should guarantee a sufficiently large buffer
                           // for a queue recording states (i,z,k,l)
    const int occ[BUF_SIZE][4],  // size: (refn+1) * 4
    const int cum[4], int refn, const char read[READ_BUF_SIZE], int readn, int *res_sa_len)
{
  // clang-format off
#pragma HLS INTERFACE s_axilite port=res_sa_len bundle=control
#pragma HLS INTERFACE s_axilite port=res_sa_itv bundle=control
#pragma HLS INTERFACE s_axilite port=buf bundle=control
#pragma HLS INTERFACE s_axilite port=occ bundle=control
#pragma HLS INTERFACE s_axilite port=cum bundle=control
#pragma HLS INTERFACE s_axilite port=refn bundle=control
#pragma HLS INTERFACE s_axilite port=read bundle=control
#pragma HLS INTERFACE s_axilite port=readn bundle=control
#pragma HLS INTERFACE s_axilite port=return bundle=control

#pragma HLS INTERFACE m_axi port=res_sa_itv offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=buf offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=occ offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=cum offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=read offset=slave bundle=gmem
#pragma HLS INTERFACE m_axi port=res_sa_len offset=slave bundle=gmem

#pragma HLS ARRAY_PARTITION variable=read complete dim=1
#pragma HLS ARRAY_PARTITION variable=cum complete dim=1
  // clang-format on

  int head = 0;
  int tail = 1;
  int res_sz = 0;

  // buf[i][0]: j
  // buf[i][1]: z (#allowed mismatches left)
  // buf[i][2]: k (left bound of SA interval)
  // buf[i][3]: l (right bound of SA interval)
  buf[0][0] = readn - 1;
  buf[0][1] = MAX_MISMATCH;
  buf[0][2] = 0;
  buf[0][3] = refn;

  int i = readn - 1;
  int z;
  int k;
  int l;
LOOP_OUTER:
  while (head < tail) {
    // clang-format off
#pragma HLS PIPELINE II=1
    // clang-format on
    i = buf[head][0];
    z = buf[head][1];
    k = buf[head][2];
    l = buf[head][3];
    head++;

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

    // debug("head=%d tail=%d i=%d z=%d k=%d l=%d", head, tail, i, z, k, l);

    // insert
    buf[tail][0] = i - 1;
    buf[tail][1] = z - 1;
    buf[tail][2] = k;
    buf[tail][3] = l;
    tail++;
    // debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
    //       buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);

  LOOP_INNER:
    for (int s = 0; s < 4; s++) {
#pragma HLS UNROLL
      int o = 0;
      if (k > 0)
        o = occ[k - 1][s];
      int k_nxt = cum[s] + o;
      int l_nxt = cum[s] + occ[l][s] - 1;

      if (k_nxt <= l_nxt) {
        // SNP (substitute) alpha[s]
        buf[tail][0] = i;
        buf[tail][1] = z - 1;
        buf[tail][2] = k_nxt;
        buf[tail][3] = l_nxt;
        tail++;
        // debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
        //       buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);

        if (match_symbol(s, read[i])) {
          // match alpha[s]
          buf[tail][0] = i - 1;
          buf[tail][1] = z;
          buf[tail][2] = k_nxt;
          buf[tail][3] = l_nxt;
          tail++;
          // debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
          //       buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);
        }
        else {
          // delete alpha[s]
          buf[tail][0] = i - 1;
          buf[tail][1] = z - 1;
          buf[tail][2] = k_nxt;
          buf[tail][3] = l_nxt;
          tail++;
          // debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
          //       buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);
        }
      }
    }
  }
  *res_sa_len = res_sz;
}
}
