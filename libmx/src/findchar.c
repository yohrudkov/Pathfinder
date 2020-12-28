#include "libmx.h"

int mx_findchar(char *str, char ch) {
    for (int i = 0; str[i]; i++)
        if (str[i] == ch)
            return i;
    return -1;
}
