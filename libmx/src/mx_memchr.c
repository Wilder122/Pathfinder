#include "../inc/libmx.h"

void *mx_memchr(const void *memory, int character, size_t size) {
    const unsigned char *data = (const unsigned char *)memory;

    while (size--) {
        if (*data == (unsigned char)character) {
            return (void *)data;
        }
        data++;
    }

    return NULL;
}


