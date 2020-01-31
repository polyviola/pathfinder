#include "libmx.h"

int mx_get_char_index(const char *str, char c) {
    int len = 0;

    if (str == NULL) {
        return -2;
    }
    for (int i = 0; str[i] != 0; i++) {
        len++;
    }
    for (int i = 0; i <= len; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}
