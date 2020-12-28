#ifndef LIBMX_H
#define LIBMX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <malloc/malloc.h>

#define FIRST	0x01
#define SECOND	0x02

#define COUT	0x01
#define CERR	0x02

typedef struct s_list {
	void *data;
	struct s_list *next;
}			   t_list;

int mx_strlen(char *str);
int mx_listsize(t_list *list);
int mx_findchar(char *str, char ch);
int mx_strcmp(char *str1, char *str2);
int mx_getline(char **line, char delim, int *fd);
char *mx_newstr(int size);
char *mx_strcopy(char *str);
char *mx_add_char(char **line, char ch);
char *mx_strjoin(char *str1, char *str2);
char *mx_copylen(char *str, int from, int to);
char *mx_superjoin(char **str1, char **str2, uint8_t flag);
bool mx_foreach(char *str, bool (*f)(int));
bool mx_isalpha(int ch);
bool mx_isdigit(int ch);
void mx_free(char **str);
void mx_strdel(char **str);
void mx_push_front(t_list** list, void *data);
void mx_push_back(t_list** list, void *data);
void mx_trim_all(t_list **list, void (*f)(void *));
t_list *mx_new_node(void *data);

#endif
