#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_cllist {
	int pid;
	char *str;
	struct s_cllist *link;
} t_cllist;

extern t_cllist *g_l;

// circular linked list
void add_last(int pid);
int search(int pid);
void delete_node(int pid);
void print_list(void);

