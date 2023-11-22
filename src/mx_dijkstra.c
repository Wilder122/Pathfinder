#include "pathfinder.h"

int mx_find_lowest_cost_node(int costs[], int processed[], int vertices_num) {
	int lowest_cost = MAX_INT;
	int lowest_cost_node = -1;

	for (int i = 0; i < vertices_num; i++) {
		int cost = costs[i];

		if (cost < lowest_cost && processed[i] != 1) {
			lowest_cost = cost;
			lowest_cost_node = i;
		}
	}

	return lowest_cost_node;
}

void mx_find_shortest_paths(int **matrix, int* costs, int* processed, t_list** parents, int vertices_num) {
	int node = mx_find_lowest_cost_node(costs, processed, vertices_num);

	while (node != -1) {
		int cost = costs[node];

		for (int i = 0; i < vertices_num; i++) {
			if (matrix[i][node] == 0) {
				continue;
			}

			int new_cost = cost + matrix[i][node];
			if (costs[i] > new_cost) {
				costs[i] = new_cost;
                void *ptr_to_node = malloc(sizeof(int));
                *((int *) ptr_to_node) = node;
				if (parents[i] != NULL) {
					mx_clear_list(&parents[i]);
				}
				parents[i] = mx_create_node(ptr_to_node);
			} else if (costs[i] == new_cost) {
                void *ptr_to_node = malloc(sizeof(int));
                *((int *) ptr_to_node) = node;
                mx_push_back(&parents[i], ptr_to_node);
            }
		}


		processed[node] = 1;
		node = mx_find_lowest_cost_node(costs, processed, vertices_num);
	}
}

