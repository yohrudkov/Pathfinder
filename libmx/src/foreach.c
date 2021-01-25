#include "../inc/libmx.h"

bool mx_foreach(char *str, bool (*f)(int)) {
    for (int i = 0; str[i]; i++)
        if (!(*f)(str[i]))
            return false;
    return true;
}
