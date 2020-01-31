#include "libmx.h"

void mx_print_unicode(wchar_t c) {
    char mass[5] = {0};
    
    if (c <0x80)
        mass[0] = c & 0x7F;
    else if (c < 0x0800) {
        mass[0] = (c >> 6 & 0x1F) | 0xC0;
        mass[1] = (c & 0x3F) | 0x80;
    }
    else if (c < 0x010000) {
        mass[0] = (c >> 12 & 0x0F) | 0xE0;
        mass[1] = (c >> 6 & 0x3F) | 0x80;
        mass[2] = (c & 0x3F) | 0x80;
    }
    else {
        mass[0] = (c >> 18 & 0x07) | 0xF0;
        mass[1] = (c >> 12 & 0x3F) | 0x80;
        mass[2] = (c >> 6 & 0x3F) | 0x80;
        mass[3] = (c & 0x3F) | 0x80;
    }
    write(1, mass, mx_strlen(mass));
}
