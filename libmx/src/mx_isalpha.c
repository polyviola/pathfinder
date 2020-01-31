#include "libmx.h"

int mx_isalpha(char alpha) {
    if ((alpha > 64 && alpha < 91) || (alpha > 96 && alpha < 123))
        return 1;
    return 0;
}
