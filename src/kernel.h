#ifndef _KERNEL_H_
#define _KERNEL_H_ 1

// READ_QUEUE_LEN should be larger than NUM_PE
#define NUM_PE 2
#define READ_MAX_LEN 256
#define READ_QUEUE_LEN 2
#define BUF_SIZE 1024
#define MAX_MISMATCH 1

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
    int res_sa_len[NUM_PE], const int read_len[READ_QUEUE_LEN]);
}

#endif
