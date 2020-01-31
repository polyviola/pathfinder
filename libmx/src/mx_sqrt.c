#include "libmx.h"

int mx_sqrt(int x) {
    if (x >= 0) {
        for (int i = 0; i < 46342; i++) {
            if (i * i == x) 
                return i;
        }
        return 0;
    }
    if (x < 0) {
        return 0;
    }
    return 0;
}
