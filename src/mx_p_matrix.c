#include "pathfinder.h"

static void num_of_str(t_isl *main_s) {
    int i = 0;
    main_s->num_line = 0;

    for (; main_s->file[i] != '\0'; i++) {
        if (main_s->file[i] == '\n') {
            main_s->num_line++;
        }
    }
}

static void distance(t_isl *main_s) {
    int i = 2;
    int j = 0;
    main_s->dismas = (int *)malloc(sizeof(int) * main_s->num_line);

    for (; main_s->elem_mass[i] != NULL; i++) {
        if (mx_isdigit(main_s->elem_mass[i][0]) == 1) {
            main_s->dismas[j] = mx_atoi(main_s->elem_mass[i]);
            j++;
        }
    }
}

static void edit_matr(t_isl *main_s) {
    int i = 0;
    int j = 0;

    main_s->dis = (int**)malloc(sizeof(int*) * main_s->isl_num);
    main_s->dis_orig = (int**)malloc(sizeof(int*) * main_s->isl_num);
    for (; i < main_s->isl_num; i++) {
        main_s->dis[i] = (int*)malloc(main_s->isl_num * sizeof(int));
        main_s->dis_orig[i] = (int*)malloc(main_s->isl_num * sizeof(int));
    }
    for (i = 0; i < main_s->isl_num; i++)
        for (j = 0; j < main_s->isl_num; j++) {
            if (i == j)
                main_s->dis[i][j] = 0;
            else
                main_s->dis[i][j] = 2147483647;
        }
}

static void diss_matr(t_isl *main_s) {
    int i = 1;
    int j = 0;
    int m = 0;
    int k = 0;
    main_s->mass = (int*)malloc(sizeof(int) * 2);

    for (;  i < main_s->num_line; i++) {
        for (j = 0; j < main_s->isl_num; j++)
            if (mx_strstr(main_s->file_str[i], main_s->isl_ind[j]) != NULL) {
                main_s->mass[k] = j;
                k++;
            }
            main_s->dis[main_s->mass[0]][main_s->mass[1]] = main_s->dismas[m];
            main_s->dis[main_s->mass[1]][main_s->mass[0]] = main_s->dismas[m];
            m++;
        k = 0;
    }
}

void mx_mkmatr(t_isl *main_s) {
    int i = 0;
    int j = 0;
    
    num_of_str(main_s);
    distance(main_s);
    edit_matr(main_s);
    diss_matr(main_s);
    for (i = 0; i < main_s->isl_num; i++)
        for (j = 0; j < main_s->isl_num; j++) {
            main_s->dis_orig[i][j] = main_s->dis[i][j];
        }
}
