#include "libmx.h"

char *mx_strjoin(char *str1, char *str2) {
    char *join_str = mx_newstr(mx_strlen(str1) + mx_strlen(str2));
    int i = 0;

    if (str1 && *str1)
        for (; str1[i]; i++)
            join_str[i] = str1[i];
    i = 0;
    if (str2 && *str2)
        for (; str2[i]; i++)
            join_str[i + mx_strlen(str1)] = str2[i];
    return join_str;
}
