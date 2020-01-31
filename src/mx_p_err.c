#include "pathfinder.h"

static void error1(int argc) {
    if (argc != 2) {
        mx_printstr("usage: ./pathfinder [filename]\n", 2);
        exit(1);
    }
}

static void error2 (char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    int len;
    if (fd == -1) {
        mx_printstr("error: file ", 2);
        mx_printstr(argv[1], 2);
        mx_printstr(" does not exist\n", 2);
        close(fd);
        exit(1);
    }
    close(fd);
    len = get_len(argv[1]);
    if (len == 0) {
        mx_printstr("error: file ", 2);
        mx_printstr(argv[1], 2);
        mx_printstr(" is empty\n", 2);
        exit(1);
    }
}

int mx_errors1(int argc, char *argv[]) {
    error1(argc);
    error2(argv);
    return 0;
}
