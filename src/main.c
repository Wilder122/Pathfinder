#include "pathfinder.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        mx_error_handler(INVALID_ARGS, NULL);
    }

    char* str_file = mx_file_to_str(argv[1]);

    if (str_file == NULL) {
        mx_error_handler(INVALID_FILE, (void *) argv[1]);
    }
    if (mx_strlen(str_file) == 0) {
        mx_error_handler(FILE_EMPTY, (void *) argv[1]);
    }

    char** lines = mx_strsplit(str_file, '\n');
    int vertices_num = mx_parse_first_line(lines[0]);

    int** matrix = (int**)malloc(sizeof(int*) * vertices_num);
	for (int i = 0; i < vertices_num; i++) {
        matrix[i] = mx_alloc_and_fill_arr(-1, vertices_num);
	}

    char **vertices = (char **) malloc(sizeof(char *) * vertices_num);
    int vertices_len = 0;

    for (int i = 1; lines[i] != NULL; i++) {
        int res = mx_parse_line(matrix, vertices, &vertices_len, lines[i], vertices_num);

        if (res == -1) {
            mx_error_handler(INVALID_LINE, (void *) mx_itoa(i + 1));
        }
    }

    for (int i = 0; i < vertices_num; i++) {
        for (int j = 0; j < vertices_num; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
	}

    mx_check_invalid_sum(matrix, vertices_num);
    
    free(str_file);
    mx_del_strarr(&lines);

    for (int start_node = 0; start_node < vertices_num; start_node++) {
		int* costs = mx_alloc_and_fill_arr(MAX_INT, vertices_num);
		int* processed = mx_alloc_and_fill_arr(0, vertices_num);

        t_list** parents = (t_list**)malloc(sizeof(t_list*) * vertices_num);
        for (int i = 0; i < vertices_num; i++) {
            parents[i] = NULL;
        }

		costs[start_node] = 0;

		mx_find_shortest_paths(matrix, costs, processed, parents, vertices_num);

        mx_sort_arr_list(parents, vertices_num, mx_arr_list_cmp);

		mx_restore_paths(vertices, parents, costs, start_node, vertices_num);

		for (int i = 0; i < vertices_num; i++) {
			if (parents[i] != NULL) {
				mx_clear_list(&parents[i]);
			}
		}
		free(parents);
		free(costs);
		free(processed);
	}

    return 0;
}

