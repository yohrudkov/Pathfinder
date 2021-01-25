#include "../inc/libmx.h"

int mx_getline(char **line, char delim, int *fd) {
    char ch;
    int result = 0;

    result = read(*fd, &ch, 1);
    if (result == -1) {
        fprintf(stderr, "error: invalid filename\n");
        exit(EXIT_FAILURE);
    }
    while (result > 0) {
        if (ch == delim)
            break;
        *line = mx_add_char(line, ch);
        result = read(*fd, &ch, 1);
    }
    if (result == 0)
        return 1;
    return 0;
}
