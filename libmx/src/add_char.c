#include "../inc/libmx.h"

char *mx_add_char(char **line, char ch) {
    char *new_str = mx_newstr(mx_strlen(*line) + 1);
    int i = 0;

    for (; i < mx_strlen(*line); i++)
        new_str[i] = (*line)[i];
    new_str[i] = ch;
    mx_free(line);
    return new_str;
}
