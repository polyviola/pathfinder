#include "libmx.h"

char *mx_strjoin(char *s1, char *s2) {
    if (s1 && s2) {
        int s1len = mx_strlen(s1);
        int s2len = mx_strlen(s2);
        char *newstr = mx_strnew(s1len + s2len);

        mx_strcpy(newstr, s1);
        free(s1);
        mx_strcat(newstr, s2);
        return newstr;
    }
    else if (s2) 
        return mx_strdup(s2);
    else if (s1) 
        return mx_strdup(s1);
    else
        return NULL;
}
