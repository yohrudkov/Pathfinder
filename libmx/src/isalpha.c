#include "libmx.h"

bool mx_isalpha(int ch) {
    if ((ch >= 65 && ch <= 90)
        || (ch >= 97 && ch <= 122))
        return true;
    return false;
}
