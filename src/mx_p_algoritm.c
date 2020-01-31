#include "pathfinder.h"

void mx_floyd(t_isl *main_s) {
    int k = 0;
    int i = 0;
    int j = 0;
    int **mass = main_s->dis;
    
    main_s->path = (int**)malloc(sizeof(int*) * main_s->isl_num);
    for (; i < main_s->isl_num; i++)
        main_s->path[i] = (int*)malloc(main_s->isl_num * sizeof(int));
    for (i = 0; i < main_s->isl_num; i++)
        for (j = 0; j < main_s->isl_num; j++)
            main_s->path[i][j] = -1;
    for (; k < main_s->isl_num; k++)
        for (i = 0; i < main_s->isl_num; i++)
            for (j = 0; j < main_s->isl_num; j++)
                if (mass[i][k] + mass[k][j] < mass[i][j] 
                    && mass[i][k] != 2147483647 && mass[k][j] != 2147483647) {
                    mass[i][j] = mass[i][k] + mass[k][j];
                    main_s->path[i][j] = k;
                }
}
