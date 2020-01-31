#include "pathfinder.h"

static void error3(t_isl *main_s) {
    int i = 0;
    int index = mx_get_char_index(main_s->file_str[0], '\0');

    for (; i < index; i++) {
        if (mx_isdigit(main_s->file_str[0][i]) != 1) {
            mx_printstr("error: line 1 is not valid\n", 2);
            exit(1);
        }
    }
}

static void mod_line(t_isl *main_s) {
    int i = 0;

    for (; main_s->file1[i] != '\0'; i++) {
        if (main_s->file1[i] == ',' 
            || main_s->file1[i] == '-' || main_s->file1[i] == '\n')
            main_s->file1[i] = '$';
    }
}

static int check_line(t_isl *main_s) {
    int  i = 0;
    int ind = 0;

    for (; main_s->elem_mass[i] != NULL; i++) {
        for (ind = 0; main_s->elem_mass[i][ind] != '\0'; ind++)
            if (mx_isalpha(main_s->elem_mass[i][ind]) != 1) {
                return i;
            }
        for (i++, ind = 0; main_s->elem_mass[i][ind] != '\0'; ind++)
            if (mx_isalpha(main_s->elem_mass[i][ind]) != 1) {
                return i;
            }
        for (i++, ind = 0; main_s->elem_mass[i][ind] != '\0'; ind++)
            if (mx_isdigit(main_s->elem_mass[i][ind]) != 1) {
                return i;
            }
    }
    return -1;
}

static void error4(t_isl *main_s) {
    int i = 0;
    int check;
    int line  = 1;
    char *linestr;

    mod_line(main_s);
    for (; mx_isdigit(main_s->file1[i]) == 1; i++);
    i++;
    main_s->elem_mass = mx_strsplit(&main_s->file1[i], '$');
    check = check_line(main_s);
    if (check != -1) {
        for (; check >= 0; line++)
            check -= 3;
        linestr  = mx_itoa(line);
        mx_printstr("error: line ", 2);
        mx_printstr(linestr, 2);
        mx_printstr(" is not valid\n", 2);
        mx_strdel(&linestr);
        exit(1);
    }
}

int mx_errors2(t_isl *main_s) {
    main_s->file_str = mx_strsplit(main_s->file, '\n');
    error3(main_s);
    error4(main_s);
    return 0;
}
