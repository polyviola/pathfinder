#include "libmx.h"

int get_len(const char *file) {
    int ofi = open(file, O_RDONLY);
    int size = 0;
    char buf;
    
    if (ofi) {
        while (read(ofi, &buf, 1)) {
            size++;
        }
    }
    close(ofi);
    return size;
}
