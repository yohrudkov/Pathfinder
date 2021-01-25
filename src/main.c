#include "../inc/header.h"

static void trim_node(void *node) {
    mx_strdel(&((t_points *)node)->from);
    mx_strdel(&((t_points *)node)->to);
    mx_strdel(&((t_points *)node)->value);
}

int main(int argc, char **argv) {
    if (argc != 2)
        mx_error(0, 0);
    t_list *list;

    mx_read_from_file(&list, argv[1]);
    mx_find_all_ways(list);
    mx_trim_all(&list, trim_node);
    // system("leaks -q pathfinder");
    return 0;
}
