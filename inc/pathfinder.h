#pragma once

#include "libmx.h"

#define MAX_INT 2147483647

enum e_error {
    INVALID_ARGS,
    INVALID_FILE,
    FILE_EMPTY,
    INVALID_FIRST_LINE,
    INVALID_LINE,
    INVALID_ISLANDS_NUM,
    DUPLICATE_BRIDGES,
    INVALID_BRIDGES_SUM
};

int mx_find_lowest_cost_node(int costs[], int processed[], int cities_num);
void mx_find_shortest_paths(int **matrix, int* costs, int* processed, t_list** parents, int cities_num);
void mx_print_path(char** path, int path_len, int* cost_path, int cost_path_len);
void mx_clear_list(t_list **list);

void mx_restore_path(char** vertices, t_list** parents, t_list* current_parents, int *costs, int start_node,
                     int cities_num, char** path, int path_len, int* cost_path, int cost_path_len);
void mx_restore_paths(char** vertices, t_list** parents, int *costs, int start_node, int cities_num);

int mx_get_index_of(char** arr, int len, char* str);
bool mx_is_int(char *str);
bool mx_isalpha_str(char *str);
int* mx_alloc_and_fill_arr(int value, int len);

void mx_error_handler(enum e_error error, void* arg);
void mx_check_invalid_sum(int** matrix, int n);
int mx_parse_first_line(char *line);
int mx_parse_line(int** matrix, char** vertices, int* p_vertices_len, char* line, int max_vertices);

bool mx_arr_list_cmp(void* a, void* b);
void mx_sort_arr_list(t_list** arr, int len, bool (*cmp)(void *a, void *b));

