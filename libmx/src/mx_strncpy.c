#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i = 0;
    if (src && dst) {
        while (i < len) {
            if (i < mx_strlen(src)) {
                dst[i] = src[i];
                i++;
            }
            else {
                dst[i] = '\0';
                i++;
            }
        }
    }
    return dst;
}
