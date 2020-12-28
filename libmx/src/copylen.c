#include "libmx.h"

char *mx_copylen(char *str, int from, int to) {
    if (to > mx_strlen(str)
        || from >= to
        || from < 0)
        return NULL;
    char *new_str = mx_newstr(to - from);

    for (int i = 0; i < to - from; i++)
        new_str[i] = str[i + from];
    return new_str;
}
