#include "pathfinder.h"

void mx_err_mull(t_isl *main_s) {
    int temp = -1;
    int i = 0;
    int line = 1;

    for (i = 0; main_s->file[i] != '\n'; i++);
    i++;
    for (; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n')
            line++;
        for (temp = -1; main_s->file[i] != '\n'; i++) {
            if (main_s->file[i] == '-')
                temp = 1;
            if (main_s->file[i] == ',')
                temp = 2;
        }
        if (temp == 1)
            mx_print_errline(line);
    }
}

void mx_check_err1(t_isl *main_s) {
    int i = 0;
    int line = 1;

    for (i = 0; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n')
            line++;
        if (main_s->file[i] == '-' || main_s->file[i] == ',')
            if (main_s->file[i + 1] == '-' || main_s->file[i + 1] == ','
                || main_s->file[i + 1] == '\n')
                mx_print_errline(line);
    }
}

int mx_lensln(char *s) {
    int i = 0;
    
    while (*s != '\n' && *s != '\0') {
        i++;
        s++;
    }
    return i;
}
