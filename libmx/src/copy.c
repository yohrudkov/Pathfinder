#include "../inc/libmx.h"

char *mx_strcopy(char *str) {
    if (!str || !*str)
        return NULL;
    char *copy_str = mx_newstr(mx_strlen(str));

    for (int i = 0; str[i]; i++)
        copy_str[i] = str[i];
    return copy_str;
}
