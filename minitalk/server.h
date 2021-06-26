#include <unistd.h>
#include <signal.h>
#include "libft.h"

typedef struct s_cllist {
	int pid;
	char *str;
	struct s_cllist *link;
} t_cllist;

// circular linked list
void add_last(t_cllist **l, int pid);
int search(t_cllist **l, int pid);
void delete_node(t_cllist **l, int pid);
void print_list(t_cllist *l);
