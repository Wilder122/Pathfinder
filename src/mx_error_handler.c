#include "pathfinder.h"

void mx_error_handler(enum e_error error, void* arg) {
    switch(error) {
        case INVALID_ARGS:
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
        case INVALID_FILE:
            mx_printerr("error: file ");
            mx_printerr((char *) arg);
            mx_printerr(" does not exist\n");
            break;
        case FILE_EMPTY:
            mx_printerr("error: file ");
            mx_printerr((char *) arg);
            mx_printerr(" is empty\n");
            break;
        case INVALID_FIRST_LINE:
            mx_printerr("error: line 1 is not valid\n");
            break;
        case INVALID_LINE:
            mx_printerr("error: line ");
            mx_printerr((char *) arg);
            mx_printerr(" is not valid\n");
            break;
        case INVALID_ISLANDS_NUM:
            mx_printerr("error: invalid number of islands\n");
            break;
        case DUPLICATE_BRIDGES:
            mx_printerr("error: duplicate bridges\n");
            break;
        case INVALID_BRIDGES_SUM:
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;
    }

    exit(EXIT_FAILURE);
}

