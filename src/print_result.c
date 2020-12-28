#include "header.h"

static void reverse_list(t_list **ans) {
    t_list *prev = NULL;
    t_list *current = *ans;
    t_list *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ans = prev;
}

static void print_list(t_list *i, int flag, int sum) {
    t_list *j = i->data;

    if (j->next && flag != 0)
        j = j->next;
    for (; j; j = j->next) {
        flag == 0 ? printf("%s", ((t_graph *)j->data)->name)
                  : printf("%d", ((t_graph *)j->data)->value);
        if (j->next)
            flag == 0 ? printf(" -> ")
                      : printf(" + ");
    }
    flag == 0 ? printf("\n")
              : printf(" = %d\n", sum);
}

static int count_len(t_list *i) {
    int sum = 0;

    for (t_list *j = i->data; j; j = j->next)
        sum += ((t_graph *)j->data)->value;
    return sum;
}

void mx_print_result(t_list **ans) {
    int sum = 0;
    t_list *i = NULL;

    for (i = *ans; i; i = i->next) {
        reverse_list((t_list **)&i->data);
        if (count_len(i) < sum || sum == 0)
            sum = count_len(i);
    }
    for (i = *ans; i; i = i->next)
        if (count_len(i) == sum) {
            print_list(i, 0, sum);
            print_list(i, 1, sum);
        }
    for (i = *ans; i; i = i->next)
        mx_trim_all((t_list **)&i->data, mx_clean_graph);
    mx_trim_all(ans, NULL);
}
