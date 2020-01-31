#include "libmx.h"

int mx_isdigit(char dig) {
if (dig > 47 && dig < 58) 
    return 1;
return 0;
}
