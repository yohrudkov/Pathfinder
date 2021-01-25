#include "../inc/header.h"

static bool check_new_point(t_list *graph, char *name) {
    if (!graph)
        return true;
    for (t_list *i = graph; i; i = i->next)
        if (mx_strcmp(((t_graph *)i->data)->name, name) == 0)
            return false;
    return true;
}

static void add_ways(t_list *graph, t_points *st) {
    for (t_list *i = graph; i; i = i->next) {
        if (mx_strcmp(((t_graph *)i->data)->name, st->from) == 0
            && check_new_point(((t_graph *)i->data)->list, st->to))
            mx_push_front(&((t_graph *)i->data)->list,
                          mx_graph_node(st->to, atoi(st->value)));
        if (mx_strcmp(((t_graph *)i->data)->name, st->to) == 0
            && check_new_point(((t_graph *)i->data)->list, st->from))
            mx_push_front(&((t_graph *)i->data)->list,
                          mx_graph_node(st->from, atoi(st->value)));
    }
}

t_list *mx_create_map(t_list *list) {
    t_list *graph = NULL;

    for (t_list *i = list; i; i = i->next) {
        if (check_new_point(graph, ((t_points *)i->data)->from))
            mx_push_front(&graph,
                          mx_graph_node(((t_points *)i->data)->from, 0));
        if (check_new_point(graph, ((t_points *)i->data)->to))
            mx_push_front(&graph,
                          mx_graph_node(((t_points *)i->data)->to, 0));
        add_ways(graph, (t_points *)i->data);
    }
    return graph;
}
