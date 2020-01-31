#include "libmx.h"

static char *checknum(int number) {
    char *ret = NULL;
    if (number == -2147483648) {
        ret = "-2147483648";
        return ret;
    }
    if (number == 0) {
        ret = "0";
        return ret;
    }
    return NULL;
    
}

static int get_leng(int number) {
    int len = 0;
    while(number /= 10) {
        len++;
    }
    return len + 1;
}

char *mx_itoa(int number) {
    int size = 0;
    char *ret = NULL;
    int flag = 0;
    
    if ((ret = checknum(number)) != NULL)
        return ret;
    size = get_leng(number);
    size = number < 0 ? size + 1 : size;
    ret = mx_strnew(size + 1);
    if (number < 0) {
        number *= -1;
        flag = 1;
    }
    while (size--) {
        ret[size] = number % 10 + 48;
        number /= 10;
    }
    if (flag) 
        ret[0] = '-';
    return ret;
}
