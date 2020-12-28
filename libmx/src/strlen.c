#include "libmx.h"

int mx_strlen(char *str) {
    if (!str || !*str)
        return 0;
    int count = 0;

    for (int i = 0; str[i]; i++)
        count++;
    return count;
}
