#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new = NULL;
    size_t old_size = malloc_size(ptr);
    if (!ptr) {
        return malloc(size);
    }
    else if (size == 0 && old_size) {
        free(ptr);
        return NULL;
    }
    else {
        new = malloc(size);
        if (new == NULL) {
            return NULL;
        }
        new = mx_memcpy(new, ptr, old_size);
        free(ptr);
    }
    return new;
}
