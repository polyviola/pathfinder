#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    char *mass = (char *)s;
    
    for (size_t i = n; i >= 0; i--) {
        if (mass[i] == c) {
            return &mass[i];
        }
        if (i == 0 && mass[i] != c)
            return NULL;
    }
    return NULL;
}
