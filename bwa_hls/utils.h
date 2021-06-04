#ifndef _UTILS_H_
#define _UTILS_H_ 1

#define FOR(i, a, n) for (size_t i = a; i != n; i++)

#ifndef NDEBUG
#define debug(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)
#else
#define debug(...)
#endif

#endif