#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    int len = -1;
    unsigned long res = 0;
    if (!hex) 
        return 0;
    for (int i = 0; hex[i] != '\0'; i++, len++);
    for (int i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= 'A' && hex[i] <= 'F') {
            res += (hex[i] - 55) * mx_pow(16, (len - i));
        }
        if (hex[i] >= 'a' && hex[i] <= 'f') {
            res += (hex[i] - 87) * mx_pow(16, (len - i));
        
        }
        if (hex[i] >= '0' && hex[i] <= '9') {
            res += (hex[i] - 48) * mx_pow(16, (len - i));
            
        }
    }
    return res;
}
