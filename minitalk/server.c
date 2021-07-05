#include "server.h"
#include <stdio.h>

t_cllist *g_l;

char bin_to_dec(int bin[])
{
	int i;
	int base;
	int result;

	i = 7;
	base = 1;
	result = bin[7];
	while (--i >= 0)
	{
		base *= 2;
		result += (base * bin[i]);
	}
	return (result);
}

char *append_char(char *str, int *size, char c)
{
	int strlen;
	char *new;

	if (str == NULL)
	{
		str[0] = c;
		return str;
	}
	strlen = 0;
	while (str[strlen] != 0)
		strlen++;
	if (strlen < *size)
	{
		str[strlen] = c;
		return str;
	}
	*size *= 2;
	new = (char *)malloc(*size);
	ft_memset(new, 0, *size);
	ft_memcpy(new, str, (*size / 2));
	free(str);
	return new;
}

void proc(int signum, siginfo_t *info, void *oact)
{
	printf("signo :%d\n", signum);
	//char *pid = ft_itoa(info->si_pid);
	t_cllist *l;
	int sign;

	oact = NULL;
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
			print_list();
			l = search(info->si_pid);
			l->bin[0] = sign;
			l->binlen = 1;
			//printf("after : ");
			//(void)signum;
			return ;
		}
		else if (l->binlen == 8)
		{
			l->str = append_char(l->str, &(l->str_size), bin_to_dec(l->bin));
			printf("l->str : %s\n", l->str);
			ft_memset(l->bin, 0, 8);
			l->binlen = 0;
		}
		l->bin[l->binlen++] = sign;
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
