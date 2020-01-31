#include "libmx.h"

static int mx_check(const char *s1, size_t n) {
    size_t size = 0;
    
    while (s1[size++]); 
    return size - 1 > n ? size - 1 : n;
}

char *mx_strndup(const char *s1, size_t n) {
    char *newstr = s1 ? mx_strnew(mx_check(s1, n)) : NULL;
    return newstr ? mx_strncpy(newstr, s1, n) : NULL;
}
