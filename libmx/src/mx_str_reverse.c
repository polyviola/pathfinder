#include "libmx.h"

void mx_str_reverse(char *s) {
    int len = 0;
    char *begin = s;
    char *end = s;
    for (int i = 0; s[i] != '\0'; i++) {
        len++; 
    }
    for (int i = 0; i < len - 1; i++)
        end++;
    for (int i = 0; i < len / 2; i++) {
        mx_swap_char(begin, end);
        begin++;
        end--;
    }
}
