#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_cllist {
	int pid;
	int bin[8];
	int b_idx;
	char *str;
	int str_idx;
	int sb[32];
	int sb_idx;
	int strlen;
	struct s_cllist *link;
} t_cllist;

extern t_cllist *g_l;

// circular linked list
void add_last(int pid);
t_cllist *search(int pid);
void delete_node(int pid);
void print_list(void);
