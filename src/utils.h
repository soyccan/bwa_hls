#ifndef _UTILS_H_
#define _UTILS_H_ 1

#include <cstdio>

#define FOR(i, a, n) for (size_t i = a; i != n; i++)

#define array_size(arr) (sizeof(arr) / sizeof((arr)[0]))

#define debug(...)
#define debugn(...)

#ifndef NDEBUG
#ifndef __SYNTHESIS__
#undef debug
#undef debugn
#define debug(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#define debugn(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#endif
#endif


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

#endif