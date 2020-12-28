#include "libmx.h"

int mx_strcmp(char *str1, char *str2) {
    int i = 0;

    for (; str1[i] && str2[i]; i++)
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
    return str1[i] - str2[i];
}
