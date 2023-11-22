#include "pathfinder.h"

bool mx_arr_list_cmp(void* a, void* b) {
    return mx_strcmp((char *) a, (char *) b) < 0;
}

void mx_sort_arr_list(t_list** arr, int len, bool (*cmp)(void *a, void *b)) {
    for (int i = 0; i < len; i++) {
        mx_sort_list(arr[i], cmp);
    }
}

