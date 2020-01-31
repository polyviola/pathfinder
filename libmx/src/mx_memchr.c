#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    char *mass = (char *)s;
    
    for (size_t i = 0; i < n; i++) {
        if (mass[i] == c) {
            return &mass[i];
        }
    }
    return NULL;
}
