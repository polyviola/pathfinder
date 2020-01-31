#include "pathfinder.h"

static int ischarstr(char *str) {
    int i = 0;

    for (; str[i] != '\0'; i++) 
        if (mx_isalpha(str[i]) != 1) {
            return 1;
        }
    return 0;
}

static int am_mass_el(char **strmass) {
    int i = 0;
    int count = 0;

    for(; strmass[i] != NULL; i++) {
        count++;
    }
    return count;
}

static void indiv_isl(t_isl *main_s) {
    int i = 1;
    char *isl = NULL;

    isl = mx_strjoin(isl, main_s->elem_mass[0]);
    isl = mx_strjoin(isl, " ");
    for (; main_s->elem_mass[i] != NULL; i++) {
        if (!mx_strstr(isl, main_s->elem_mass[i]) 
            && ischarstr(main_s->elem_mass[i]) != 1) {
            isl = mx_strjoin(isl, main_s->elem_mass[i]);
            isl = mx_strjoin(isl, " ");
        }
    }
    main_s->isl_ind = mx_strsplit(isl, ' ');
    mx_strdel(&isl);
    main_s->isl_num = am_mass_el(main_s->isl_ind);
}

static void error5(t_isl *main_s) {
    int amount = mx_atoi(main_s->file_str[0]);
    if (amount != main_s->isl_num) {
        mx_printstr("error: invalid number of islands\n", 2);
        exit(1);
    }
}

int mx_errors3(t_isl *main_s) {
    indiv_isl(main_s);
    error5(main_s);
    return 0;
}
