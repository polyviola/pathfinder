#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *s = (unsigned char *)malloc(len);

    mx_memcpy(s, src, len);
    mx_memcpy(dst, s, len);
    
    free(s);
    return dst;
}
