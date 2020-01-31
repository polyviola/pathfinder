#include "libmx.h"

char *mx_strnew(const int size) {
    char *p = NULL;
    
    if (size >= 0) {
        if ((p = (char *)malloc(size + 1)) == NULL) {
            return NULL;
        }
        else
            for (int i = 0; i < size; i++) {
                p[i] = '\0';
            }
        p[size] = '\0';
        return p;
    }
    else 
        return NULL;
}
