#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"

typedef struct s_cllist {
	int bin[8];
	int b_idx;
	char *str;
	int str_idx;
	int sb[32];
	int sb_idx;
	int strlen;
} t_cllist;

extern t_cllist g_l;