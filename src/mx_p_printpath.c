#include "pathfinder.h"

static void print_fnl(t_isl *main_s, t_stack *p_st) {
    mx_printstr(main_s->isl_ind[p_st->path[1]], 1);
    mx_printstr(" -> ", 1);
    mx_printstr(main_s->isl_ind[p_st->path[0]], 1);
    mx_printstr("\n", 1);
}

static void print_route(t_isl *main_s, t_stack *p_st) {
    int i = 1;

    for (i = 1; i <= p_st->size; i++) {
        mx_printstr(main_s->isl_ind[p_st->path[i]], 1);
        if (i < p_st->size)
            mx_printstr(" -> ", 1);
        else 
            mx_printstr("\n", 1);
    }
}

static void print_dis(t_isl *main_s, t_stack *p_st) {
    int dis = 0;
    int n = p_st->size;
    int i = 1;

    if (n == 2) {
        mx_printint(main_s->dis[p_st->path[n]][p_st->path[n - 1]], 1);
    }
    else {
        for (i = 1; i < n; i++) {
            mx_printint(main_s->dis[p_st->path[i]][p_st->path[i + 1]], 1);
            dis += main_s->dis[p_st->path[i]][p_st->path[i + 1]];
            if (i + 1 < n) {
                mx_printstr(" + ", 1);
            }
            else {
                mx_printstr(" = ", 1);
                mx_printint(dis, 1);
            }
        }
    }
    mx_printstr("\n", 1);
}

void mx_printpath(t_isl *main_s, t_stack *p_st) {
    mx_printstr("========================================\n", 1);
    mx_printstr("Path: ", 1);
    print_fnl(main_s, p_st);
    mx_printstr("Route: ", 1);
    print_route(main_s, p_st);
    mx_printstr("Distance: ", 1);
    print_dis(main_s, p_st);
    mx_printstr("========================================\n", 1);
}
