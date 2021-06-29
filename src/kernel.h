#ifndef _KERNEL_H_
#define _KERNEL_H_ 1

// READ_QUEUE_LEN should be larger than NUM_PE
#define READ_MAX_LEN 64
#define BUF_SIZE 256
#define LOCAL_BUF_SIZE 128
#define MAX_MISMATCH 1

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

    const char read[READ_MAX_LEN], int read_len);
}

#endif
