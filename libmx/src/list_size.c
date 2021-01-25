#include "../inc/libmx.h"

int mx_listsize(t_list *list) {
    int size = 0;

    for (t_list *i = list; i; i = i->next)
        size++;
    return size;
}
