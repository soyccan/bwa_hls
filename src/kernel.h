#ifndef _KERNEL_H_
#define _KERNEL_H_ 1

#define READ_BUF_SIZE 256
#define BUF_SIZE 1024
#define MAX_MISMATCH 1

extern "C" {
void bwa_align(
    int res_sa_itv[BUF_SIZE][2],  // output SA intervals
    int buf[BUF_SIZE][4],  // host should guarantee a sufficiently large buffer
                           // for a queue recording states (i,z,k,l)
    const int occ[BUF_SIZE][4],  // size: (refn+1) * 4
    const int cum[4], int refn, const char read[READ_BUF_SIZE], int readn, int *res_sa_len);
}

#endif
