#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int entry = -1;
    int haylen = mx_strlen(haystack);
    int needlen = mx_strlen(needle);
    
    if (needlen == 0 && haylen != 0)
        return (char *)haystack;
    for (int i = 0, j = 0; i <= haylen; i++) {
        while (haystack[i] != needle[j]) {
            if (haystack[i + 1] == '\0')
                return NULL;
            i++;
        }
        if (haystack[i] == needle[0])
                entry = i;
        while(haystack[i] == needle[j]) {
                if (needle[j + 1] == '\0')
                return (char *)&haystack[entry];
            i++;
            j++;
        }
        if (haystack[i] == '\0')
            return NULL;
        i--;
        j = 0;
    }
    return NULL;
}
