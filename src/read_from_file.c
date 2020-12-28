#include "header.h"

static void check_line(char *line, t_list **list) {
    if (!line
        || mx_findchar(line, '=') == 0
        || mx_findchar(line, '-') == 0
        || mx_findchar(line, '=') == -1
        || mx_findchar(line, '-') == -1
        || mx_findchar(line, '=') == mx_strlen(line) - 1
        || mx_findchar(line, '-') == mx_strlen(line) - 1)
        mx_error(1, mx_listsize(*list) + 1);
}

static bool the_same(t_points *st, t_list **list) {
    for (t_list *i = *list; i; i = i->next)
        if (((mx_strcmp(((t_points *)i->data)->from, st->from) == 0
                    && mx_strcmp(((t_points *)i->data)->to, st->to) == 0)
                || (mx_strcmp(((t_points *)i->data)->from, st->to) == 0
                    && mx_strcmp(((t_points *)i->data)->to, st->from) == 0))
            && mx_strcmp(((t_points *)i->data)->value, st->value) != 0)
            return false;
    return true;
}

static void check_struct(t_points *st, t_list **list) {
    if (mx_strcmp(st->to, st->from) == 0
        || !mx_foreach(st->from, mx_isalpha)
        || !mx_foreach(st->to, mx_isalpha)
        || !mx_foreach(st->value, mx_isdigit))
        mx_error(1, mx_listsize(*list) + 1);
    if (!the_same(st, list))
        mx_error(2, mx_listsize(*list) + 1);
}

static void check_push(char *line, t_list **list) {
    t_points *st = (t_points *)malloc(sizeof(t_points));

    check_line(line, list);
    st->from = mx_copylen(line, 0, mx_findchar(line, '-'));
    st->to = mx_copylen(line,
                        mx_findchar(line, '-') + 1,
                        mx_findchar(line, '='));
    st->value = mx_copylen(line,
                           mx_findchar(line, '=') + 1,
                           mx_strlen(line));
    check_struct(st, list);
    mx_push_front(list, st);
}

void mx_read_from_file(t_list **list, char *str_path) {
    int fd = open(str_path, O_RDONLY);
    int lines = 0;
    char *line = NULL;

    while (mx_getline(&line, '\n', &fd) != 1) {
        check_push(line, list);
        mx_strdel(&line);
        lines += 1;
    }
    if (lines == 0)
        mx_error(3, 0);
    check_push(line, list);
    mx_strdel(&line);
}
