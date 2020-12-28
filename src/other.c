#include "header.h"

void mx_error(int flag, int value) {
    if (flag == 0)
        fprintf(stderr, "usage: ./pathfinder [filename]\n");
    else if (flag == 1) {
        fprintf(stderr, "error: line %d isn't valid\n", value);
        fprintf(stderr, "Line format:\n");
        fprintf(stderr, "\t[Name(from)]-[Name(to)]=[Value]\n");
        fprintf(stderr, "\t[Name] contains only letters\n");
        fprintf(stderr, "\t[Value] contains only digits\n");
    }
    else if (flag == 2) {
        fprintf(stderr, "error: line %d already", value);
        fprintf(stderr, " exist with the different value\n");
    }
    exit(EXIT_FAILURE);
}

t_graph *mx_graph_node(char *name, int value) {
    t_graph *node = (t_graph *)malloc(sizeof(t_graph));

    node->name = mx_strcopy(name);
    node->value = value;
    node->list = NULL;
    return node;
}

void mx_clean_graph(void *node) {
    if (((t_graph *)node)->list)
        mx_trim_all(&((t_graph *)node)->list, mx_clean_graph);
    mx_strdel(&((t_graph *)node)->name);
}
