#ifndef _KERNEL_H_
#define _KERNEL_H_ 1

int bwa_align(int res_sa_itv[][2],  // output SA intervals
              int buf[][4],  // host should guarantee a sufficiently large
                             // buffer for a queue recording states (i,z,k,l)
              const int occ[][4], const int cum[4], int refn, const char read[],
              int readn);

#endif