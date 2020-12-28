#include "libmx.h"

bool mx_isdigit(int ch) {
    if (ch >= 48 && ch <= 57)
        return true;
    return false;
}

