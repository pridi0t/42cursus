#include "server.h"
#include <stdio.h>

t_cllist *g_l;

char bin_to_dec(int bin[], int blen)
{
	int i;
	int base;
	int result;

	i = blen - 1;
	base = 1;
	result = bin[blen - 1];
	while (--i >= 0)
	{
		base *= 2;
		result += (base * bin[i]);
	}
	return (result);
}

void append_char(t_cllist *l, char c)
{
	if (l->str == NULL)
	{
		l->str = (char *)malloc(l->strlen);
		ft_memset(l->str, 0, l->strlen);
		l->str[0] = c;
		l->str_idx = 1;
		return ;
	}
	l->str[l->str_idx++] = c;
}

void proc(int signum, siginfo_t *info, void *oact)
{
	//printf("signo :%d\n", signum);
	//char *pid = ft_itoa(info->si_pid);
	t_cllist *l;
	int sign;

	oact += 0;
	sign = 0;
	if (signum == SIGUSR1)
		sign = 1;
	if (sign == 0 || sign == 1)
	{
		///write(1, "\nclient PID : ", 15);
		//write(1, pid, ft_strlen(pid));
		//write(1, "\n", 2);
		l = search(info->si_pid);
		if (l == NULL)
		{
			add_last(info->si_pid);
			//print_list();
			l = search(info->si_pid);
			l->bin[0] = sign;
			l->b_idx = 1;
			//printf("after : ");
			//(void)signum;
			return ;
		}
		if (l->strlen == -1 && l->sb_idx != 32)
			l->sb[l->sb_idx++] = sign;
		else if (l->strlen == -1 && l->sb_idx == 32)
			l->strlen = bin_to_dec(l->sb, 32);
		else
			l->bin[l->b_idx++] = sign;
		if (l->b_idx == 7)
		{
			append_char(l, bin_to_dec(l->bin, 8));
			//printf("l->str : %s\n", l->str);
			ft_memset(l->bin, 0, sizeof(int) * 8);
			l->b_idx = 0;
		}
		if ((int)ft_strlen(l->str) == l->strlen)
		{
			printf("%s", l->str);
			return;
		}
	}
}

int main(void)
{
	struct sigaction act;
	char *pid = ft_itoa(getpid());
	
	write(1, "server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	act.sa_sigaction = proc;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while(1)
	{
		pause();
	}
	return 0;
}
