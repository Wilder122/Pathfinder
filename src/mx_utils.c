#include "pathfinder.h"

int mx_get_index_of(char** arr, int len, char* str) {
    for (int i = 0; i < len; i++) {
        if (arr[i] != NULL && mx_strcmp(arr[i], str) == 0) {
            return i;
        }
    }

    return -1;
}

bool mx_is_int(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

bool mx_isalpha_str(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isalpha(str[i])) {
            return false;
        }
    }

    return true;
}

int* mx_alloc_and_fill_arr(int value, int len) {
	int *arr = (int*)malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++) {
		arr[i] = value;
	}

	return arr;
}

