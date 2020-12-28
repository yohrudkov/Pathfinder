#include "libmx.h"

void mx_free(char **str) {
    if (!str || !*str)
        return;
    free(*str);
    *str = NULL;
}
