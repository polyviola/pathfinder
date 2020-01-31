#include "libmx.h"

bool mx_isspace(int c) {
    return c == ' ' || (c > 8 && c < 14);
}
