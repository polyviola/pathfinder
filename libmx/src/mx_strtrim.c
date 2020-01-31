#include "libmx.h"

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = mx_strlen(str ? str : "");

    end = end == 0 ? 0 : end - 1;
    char *newmass = NULL;

    if (str) {
        while (mx_isspace(str[start])) 
            start++;
        while (mx_isspace(str[end]) && end > start)
            end--;
        newmass = mx_strnew(end > start ? end - start + 1 : 0);
        mx_strncpy(newmass, str + start, end - start + 1);
    }
    return newmass;
}
