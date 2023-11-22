#include "pathfinder.h"

void mx_clear_list(t_list **list) {
    if (*list == NULL) {
        return;
    }

    t_list *current = *list;

    while(current) {
        t_list *temp = current;
        current = current->next;
		free(temp->data);
        free(temp);
    }

    *list = NULL;
}

