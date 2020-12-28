#include "libmx.h"

void mx_push_back(t_list** list, void *data) {
    if (!list)
        return;
    t_list *node = mx_new_node(data);

    if (!*list)
        *list = node;
    else {
        t_list *i = *list;

        for (; i->next != NULL; i = i->next);
        i->next = node;
    }
}
