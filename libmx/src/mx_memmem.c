#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    char *bigs = (char *)big;

    if (big_len < little_len || big_len == 0 || little_len == 0) {
        return NULL;
    }
    for (size_t i = 0; i < big_len; i++, bigs++) {
        if (mx_memcmp(bigs, little, little_len) == 0) {
            return (void *)bigs;
        }
    }
    return NULL;
}
