#include "pathfinder.h"

static void init_stack(t_isl *main_s, t_stack **p_st, int i, int j) {
    *p_st = malloc(sizeof(t_stack));
    int n = main_s->isl_num;

    if ((*p_st) == NULL)
        exit(1);
    (*p_st)->path = malloc(sizeof(int)* n + 1);
    (*p_st)->size = 1;
    (*p_st)->path[1] = i;
    (*p_st)->path[0] = j;
    (*p_st)->n = n;
}

void mx_p_findpath(t_isl *main_s, int st, int end) {
    t_stack *p_st = NULL;

    init_stack(main_s, &p_st, st, end);
    mx_backtrack(main_s, p_st);
    free(p_st->path);
    free(p_st);
}
