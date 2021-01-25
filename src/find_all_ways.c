#include "../inc/header.h"

static t_list *copy_visited(t_list *visited, char *name, int value) {
    t_list *copy = NULL;

    for (t_list *i = visited; i; i = i->next)
        mx_push_back(&copy,
                     mx_graph_node(((t_graph *)i->data)->name,
                                   ((t_graph *)i->data)->value));
    mx_push_front(&copy, mx_graph_node(name, value));
    return copy;
}

static bool can_not_back(t_list *visited, t_list *i) {
    for (t_list *j = visited; j; j = j->next)
        if (mx_strcmp(((t_graph *)j->data)->name,
                      ((t_graph *)i->data)->name) == 0)
            return true;
    return false;
}

static t_list *go_next(t_list *graph, t_list *visited) {
    for (t_list *i = graph; i; i = i->next)
        if (mx_strcmp(((t_graph *)i->data)->name,
                      ((t_graph *)visited->data)->name) == 0)
            return ((t_graph *)i->data)->list;
    return NULL;
}

static void find_path(t_list *graph, char *name, t_list **visited, t_list **ans) {
    if (mx_strcmp(name, ((t_graph *)(*visited)->data)->name) == 0) {
        mx_push_front(ans, *visited);
        *visited = NULL;
        return;
    }
    for (t_list *i = go_next(graph, *visited); i; i = i->next) {
        if (!can_not_back(*visited, i)) {
            t_list *copy = copy_visited(*visited,
                                        ((t_graph *)i->data)->name,
                                        ((t_graph *)i->data)->value);

            find_path(graph, name, &copy, ans);
            mx_trim_all(&copy, mx_clean_graph);
        }
    }
    mx_trim_all(visited, mx_clean_graph);
}

void mx_find_all_ways(t_list *list) {
    t_list *graph = mx_create_map(list);
    t_list *visited = NULL;
    t_list *ans = NULL;

    for (t_list *i = graph; i; i = i->next) {
        for (t_list *j = graph; j; j = j->next)
            if (mx_strcmp(((t_graph *)i->data)->name,
                          ((t_graph *)j->data)->name) != 0) {
                mx_push_front(&visited,
                              mx_graph_node(((t_graph *)i->data)->name, 0));
                find_path(graph, ((t_graph *)j->data)->name, &visited, &ans);
                mx_print_result(&ans);
            }
        if (i->next)
            printf("<<====================>>\n");
    }
    mx_trim_all(&graph, mx_clean_graph);
}
