#include "../inc/libmx.h"

char *mx_superjoin(char **str1, char **str2, uint8_t flag) {
    char *str_new = mx_strjoin(*str1, *str2);

    if (flag & FIRST)
        mx_free(str1);
    if (flag & SECOND)
        mx_free(str2);
    return str_new;
}
