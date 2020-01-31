#ifndef PATHFINDER_H
#define PATHFINDER_H
#include "libmx.h"

typedef struct s_isl {
    char *file;
    char *file1;
    char **file_str;
    char **elem_mass;
    char **isl_ind;
    int isl_num;
    int num_line;
    int *dismas;
    int **dis;
    int **dis_orig;
    int **path;
    int *mass;
} t_isl;

typedef struct s_stack {
    int *path;
    int size;
    int n;
} t_stack;

int mx_errors1(int argc, char *argv[]);
int mx_errors2(t_isl *main_s);
int mx_errors3(t_isl *main_s);
void mx_check_err(t_isl *main_s);
void mx_check_err1(t_isl *main_s);
void mx_err_mull(t_isl *main_s);
void mx_print_errline(int line);
void mx_mkmatr(t_isl *main_s);
void mx_floyd(t_isl *main_s);
void mx_p_findpath(t_isl *main_s, int st, int end);
void mx_backtrack(t_isl *main_s, t_stack *p_st);
void mx_printpath(t_isl *main_s, t_stack *p_st);
int mx_lensln(char *s);

#endif
