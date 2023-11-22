#include "pathfinder.h"

int mx_parse_line(int** matrix, char** vertices, int* p_vertices_len, char* line, int max_vertices) {
    int vertices_len = *p_vertices_len;
    int hyphen = mx_get_char_index(line, '-');
    int comma = mx_get_char_index(line, ',');

    if (hyphen < 0 || comma < 0 || !mx_is_int(line + comma + 1)) {
        return -1;
    }

    char *vertex1 = mx_strndup(line, hyphen);
    char *vertex2 = mx_strndup(line + hyphen + 1, comma - hyphen - 1);
    int distance = mx_atoi(line + comma + 1);

    if (mx_strlen(vertex1) == 0 || mx_strlen(vertex2) == 0 ||
        !mx_isalpha_str(vertex1) || !mx_isalpha_str(vertex2) ||
        mx_strcmp(vertex1, vertex2) == 0 || distance < 0) {
        return -1;
    }

    if (mx_get_index_of(vertices, vertices_len, vertex1) == -1) {
        if (vertices_len == max_vertices) {
            mx_error_handler(INVALID_ISLANDS_NUM, NULL);
        }

        vertices[vertices_len++] = mx_strdup(vertex1);
    }
    if (mx_get_index_of(vertices, vertices_len, vertex2) == -1) {
        if (vertices_len == max_vertices) {
            mx_error_handler(INVALID_ISLANDS_NUM, NULL);
        }

        vertices[vertices_len++] = mx_strdup(vertex2);
    }

    int vertex1_i = mx_get_index_of(vertices, vertices_len, vertex1);
    int vertex2_i = mx_get_index_of(vertices, vertices_len, vertex2);

    if (matrix[vertex1_i][vertex2_i] != -1 || matrix[vertex2_i][vertex1_i] != -1) {
        mx_error_handler(DUPLICATE_BRIDGES, NULL);
    }

    matrix[vertex1_i][vertex2_i] = distance;
    matrix[vertex2_i][vertex1_i] = distance;

    *p_vertices_len = vertices_len;

    free(vertex1);
    free(vertex2);

    return 1;
}

