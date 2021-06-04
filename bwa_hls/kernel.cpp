#include "kernel.h"

#include "bwa.h"
#include "utils.h"


#define MAX_MISMATCH 1

int bwa_align(int res_sa_itv[][2],  // output SA intervals
              int buf[][4],  // host should guarantee a sufficiently large
                             // buffer for a queue recording states (i,z,k,l)
              const int occ[][4],  // size: (refn+1) * 4
              const int cum[4], int refn, const char read[], int readn)
{
  static const char alpha[] = "ACGT";
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
  while (head < tail) {
    i = buf[head][0];
    z = buf[head][1];
    k = buf[head][2];
    l = buf[head][3];
    head++;

    if (i < 0) {
      printf("found SA interval [%d, %d]\n", k, l);
      res_sa_itv[res_sz][0] = k;
      res_sa_itv[res_sz][0] = l;
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
    tail++;
    debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
          buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);

    for (int s = 0; s < 4; s++) {
      int k_nxt;
      int l_nxt;
      if (k > 0)
        k_nxt = cum[s] + occ[k - 1][s];
      else
        k_nxt = cum[s];
      l_nxt = cum[s] + occ[l][s] - 1;

      if (k_nxt <= l_nxt) {
        // SNP (substitute) alpha[s]
        buf[tail][0] = i;
        buf[tail][1] = z - 1;
        buf[tail][2] = k_nxt;
        buf[tail][3] = l_nxt;
        tail++;
        debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
              buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);

        if (alpha[s] == read[i]) {
          // match alpha[s]
          buf[tail][0] = i - 1;
          buf[tail][1] = z;
          buf[tail][2] = k_nxt;
          buf[tail][3] = l_nxt;
          tail++;
          debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
                buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);
        }
        else {
          // delete alpha[s]
          buf[tail][0] = i - 1;
          buf[tail][1] = z - 1;
          buf[tail][2] = k_nxt;
          buf[tail][3] = l_nxt;
          tail++;
          debug("tail=%d i=%d z=%d k=%d l=%d", tail, buf[tail - 1][0],
                buf[tail - 1][1], buf[tail - 1][2], buf[tail - 1][3]);
        }
      }
    }
  }
  return res_sz;
}