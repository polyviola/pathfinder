#include "pathfinder.h"

static void check2(t_isl *main_s) {
    int i = 0;
    int line = 1;

    if (main_s->file[0] == '\n' && main_s->file[1] == '\0')
        mx_print_errline(1);
    for (i = 0; mx_isdigit(main_s->file[i]) == 1; i++) {
        if (main_s->file[i + 1] == '\n' && main_s->file[i + 2] == '\0') {
            mx_printstr("error: invalid number of islands\n", 2);
            exit(1);
        }
    }
    for (i = 0; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n')
            line++;
        if (main_s->file[i] == '\n' && main_s->file[i + 1] == '\n') {
            mx_print_errline(line);
        }
    }
}

static void check1(t_isl *main_s) {
    int i = 0;
    int len = 0;

    for (i = 0; main_s->file[i] == 0; i++);
    for (; main_s->file[i] != '\n' && mx_isdigit(main_s->file[i]) == 1; i++)
        len++;
    if (len > 10) {
        mx_print_errline(1);
    }
}

static void check0(t_isl *main_s) {
    int  i = 0;
    int line = 1;

    if (main_s->file[0] == '\n') {
        mx_print_errline(1);
    }
    for (i = 0; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n')
            line++;
        if (main_s->file[i] != '\n' && main_s->file[i + 1] == '\0') {
            mx_print_errline(line);
        }
    }
}

static void check_dissum(t_isl *main_s) {
    int i = 0;
    unsigned long int sum = 0;
    int len = 0;
    int line = 1;

    for (i = 0; main_s->file[i] != '\n'; i++);
    for (; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n')
            line++;
        if (mx_isdigit(main_s->file[i]) == 1) {
            len = mx_lensln(&main_s->file[i]);
            sum += mx_atoi(&main_s->file[i]);
        }
        if (len > 10)
            mx_print_errline(line);
    }
    if (sum > 2147483647) {
        exit(1);
    }
}

void mx_check_err(t_isl *main_s) {
    check0(main_s);
    check1(main_s);
    check_dissum(main_s);
    check2(main_s);
    mx_err_mull(main_s);
}
