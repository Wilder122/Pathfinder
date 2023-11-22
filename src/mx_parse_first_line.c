#include "pathfinder.h"

int mx_parse_first_line(char *line) {
    if (!mx_is_int(line)) {
        mx_error_handler(INVALID_FIRST_LINE, NULL);
    }

    int len = mx_atoi(line);

    if (len <= 0) {
        mx_error_handler(INVALID_FIRST_LINE, NULL);
    }

    return len;
}

