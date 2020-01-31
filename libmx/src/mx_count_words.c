#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int counter = 0;
    
    if (str != NULL) {
        for (int i = 0; str[i] != '\0'; i++) {
            while (str[i] == c && str[i + 1] != '\0') {
                i++;
            }
            if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0')) {
                counter++;
            }
        }
        return counter;
    }
    else 
        return -1;
}
