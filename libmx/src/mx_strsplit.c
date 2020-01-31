#include "libmx.h"

static int str_length(const char *str, char c) {
    int len = 0;
    int i = 0;
    
    while (str[i] != c && str[i] != '\0') {
        i++;
        len++;
    }
    return len;
}
char **mx_strsplit(const char *s, char c) {
    int words = mx_count_words(s, c);
    char **mass = s ? (char **)malloc(sizeof(char *)*(words + 1)) : NULL;
        if (s && mass) {
            for (int i = 0, j = 0; s[i]; i++) {
                if (s[i] !=  c) {
                    int len = str_length(s + i, c);
                    mass[j++] = mx_strndup(s + i, len);
                    i += len;
                }
            }
        mass[words] = NULL;
    }
    return mass;
}
