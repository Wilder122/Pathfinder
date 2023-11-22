#include "pathfinder.h"

void mx_restore_path(char** vertices, t_list** parents, t_list* current_parents, int *costs, int start_node,
                     int cities_num, char** path, int path_len, int* cost_path, int cost_path_len) {
    if (current_parents->next) {
        mx_restore_path(vertices, parents, current_parents->next, costs, start_node, cities_num, path, path_len, cost_path, cost_path_len);
    }

    int current_parent = *((int *) current_parents->data);

    while (current_parent != start_node) {
        path[path_len++] = vertices[current_parent];
        cost_path[cost_path_len++] = costs[current_parent];
        current_parents = parents[current_parent];
        if (current_parents->next) {
            mx_restore_path(vertices, parents, current_parents, costs, start_node, cities_num, path, path_len, cost_path, cost_path_len);
            return;
        }
        current_parent = *((int *) current_parents->data);
    }
    path[path_len++] = vertices[current_parent];

    mx_print_path(path, path_len, cost_path, cost_path_len);
}

void mx_restore_paths(char** vertices, t_list** parents, int *costs, int start_node, int cities_num) {
	for (int i = 0; i < cities_num; i++) {
		if (parents[i] == NULL || i < start_node) {
			continue;
		}

		char** path = (char **) malloc(sizeof(char *) * cities_num);
		int path_len = 0;

		int* cost_path = (int *) malloc(sizeof(int) * cities_num);
		int cost_path_len = 0;

		path[path_len++] = vertices[i];
		cost_path[cost_path_len++] = costs[i];

        t_list* current_parents = parents[i];

        mx_restore_path(vertices, parents, current_parents, costs, start_node, cities_num, path, path_len, cost_path, cost_path_len);

		free(path);
		free(cost_path);
	}
}

