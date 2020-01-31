#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    char *a = (char *)s1;
    char *b = (char *)s2;
    
    for (size_t i = 0; i < n; i++) {
        if (a[i] != b[i])
            return a[i] - b[i];
    }
    return 0;
}
