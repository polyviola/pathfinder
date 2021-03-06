#include "libmx.h"

int mx_atoi(const char *str) {
    int sign = 0;
    int sum = 0;

    for (; mx_isspace(*str) && *str != '\n' && *str != '\0'; ++str);
    if (*str == '+' || *str == '-')
        sign = *str++ == '-';

    for (; *str && *str!= '\0' && *str != '\n' && mx_isdigit(*str); ++str)
        sum = sum * 10 + *str - 48;
    return sign ? -sum : sum;
}
