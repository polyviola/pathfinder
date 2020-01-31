#include "libmx.h"

void mx_printstr(const char *s, int potok) {
    int len = 0;
    
    while(s[len] != '\0') {
        len++;
    }
    write(potok, s, len);
}
