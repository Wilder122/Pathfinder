#include "pathfinder.h"

void mx_print_path(char** path, int path_len, int* cost_path, int cost_path_len) {
    mx_printstr("========================================\n");
	mx_printstr("Path: ");
	mx_printstr(path[path_len - 1]);
	mx_printstr(" -> ");
	mx_printstr(path[0]);
	mx_printstr("\n");

    mx_printstr("Route: ");
    for (int j = path_len - 1; j >= 0; j--) {
        mx_printstr(path[j]);

        if (j != 0) {
            mx_printstr(" -> ");
        }
    }
    mx_printstr("\n");

    mx_printstr("Distance: ");
    for (int j = cost_path_len - 1; j >= 0; j--) {
        int print_cost = cost_path[j];

        if (j != cost_path_len - 1) {
            print_cost -= cost_path[j + 1];
        }

        mx_printint(print_cost);

        if (j != 0) {
            mx_printstr(" + ");
        }
    }
    if (cost_path_len > 1) {
		mx_printstr(" = ");
		mx_printint(cost_path[0]);
    }
    mx_printstr("\n========================================\n");
}

