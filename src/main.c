#include "pathfinder.h"

void mx_print_errline(int line) {
    mx_printstr("error: line ", 2);
    mx_printint(line, 2);
    mx_printstr(" is not valid\n", 2);
    exit(1);
}

int main(int argc, char *argv[]) {
    t_isl main_s;
    int i = 0;
    int j = 0;

    if (mx_errors1(argc, argv))
        return 1;
    main_s.file = mx_file_to_str(argv[1]);
    main_s.file1 = mx_file_to_str(argv[1]);
    mx_check_err(&main_s);
    mx_check_err1(&main_s);
    if (mx_errors2(&main_s) || mx_errors3(&main_s)) 
        return 1;
    mx_mkmatr(&main_s);
    mx_floyd(&main_s);
    for (i = 0; i < main_s.isl_num; i++) {
        for (j = 0; j < main_s.isl_num; j++)
            if (i != j && i < j) 
                mx_p_findpath(&main_s, i , j);
    }
}
