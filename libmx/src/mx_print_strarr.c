#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (delim && arr) {
        for (int i = 0; arr[i] != NULL; i++) {
            mx_printstr(arr[i], 1);
            if (arr[i + 1])
            mx_printstr(delim, 1);
        }
    write(1, "\n", 1);
    }
}
