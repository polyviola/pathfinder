#include "pathfinder.h"

static int get_from_stack(t_stack *p_st) {
    return p_st->path[p_st->size];
}

static int check_next(t_isl *main_s, t_stack *p_st, int next) {
    int i = get_from_stack(p_st);
    int j = p_st->path[0];

    if (i != next) {
        if (main_s->dis_orig[i][next] == main_s->dis[j][i]
            - main_s->dis[j][next]) {
            return 1;
        }
    }
    return 0;
}

static void push_to_stack(t_stack *p_st, int i) {
    if (p_st->size < p_st->n) {
        p_st->size++;
        p_st->path[p_st->size] = i;
    }
}

static int pop_from_stack(t_stack *p_st) {
    if (p_st->size > 1) {
        p_st->size--;
        return p_st->path[p_st->size + 1];
    }
    return p_st->path[1];
}

void mx_backtrack(t_isl *main_s, t_stack *p_st) {
    int n = main_s->isl_num;
    int i = 0;

    if (get_from_stack(p_st) == p_st->path[0]) {
        mx_printpath(main_s, p_st);
        return;
    }
    else {
        for (i = 0; i < n; i++) {
            if (check_next(main_s, p_st, i)) {
                push_to_stack(p_st, i);
                mx_backtrack(main_s, p_st);
                pop_from_stack(p_st);
            }
        }
    }
}
