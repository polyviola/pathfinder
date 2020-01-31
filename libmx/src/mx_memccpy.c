#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    char *s = (char *)src;
    char *d = (char *)dst;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];
        if (s[i] == c) {
            return dst;
        }
    }
    return NULL;
}
