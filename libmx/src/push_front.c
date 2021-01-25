#include "../inc/libmx.h"

void mx_push_front(t_list** list, void *data) {
    if (!list)
        return;
    t_list *node = mx_new_node(data);

    if (!*list)
        *list = node;
    else {
        node->next = *list;
        *list = node;
    }
}
