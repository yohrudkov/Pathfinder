#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wchar.h>
#include <uuid/uuid.h>
#include <sys/uio.h>
#include <sys/acl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>
#include <malloc/malloc.h>
#include "../libmx/inc/libmx.h"

typedef struct s_points {
    char *from;
    char *to;
    char *value;
}              t_points;

typedef struct s_graph {
    t_list *list;
    char *name;
    int value;
}              t_graph;

t_graph *mx_graph_node(char *name, int value);
t_list *mx_create_map(t_list *list);
void mx_read_from_file(t_list **list, char *str_path);
void mx_find_all_ways(t_list *list);
void mx_print_result(t_list **ans);
void mx_error(int flag, int value);
void mx_clean_graph(void *node);

#endif
