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

#endif