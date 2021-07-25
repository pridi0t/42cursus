#include "server.h"
#include <stdio.h>

t_cllist g_l;

int bin_to_dec(int bin[], int blen)
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

void append_char(t_cllist *l, int c)
{
	if (l->str == NULL)
	{
		l->str = (char *)malloc(l->strlen);
		ft_memset(l->str, 0, l->strlen);
		l->str_idx = 0;
	}
	l->str[l->str_idx++] = (char)c;
}

void proc(int signum)
{
	printf("signo :%d\n", signum);
	//char *pid = ft_itoa(info->si_pid);
	int sign;

	sign = 0;
	if (signum == SIGUSR1)
		sign = 1;
	if (sign == 0 || sign == 1)
	{
		///write(1, "\nclient PID : ", 15);
		//write(1, pid, ft_strlen(pid));
		//write(1, "\n", 2);
		
		if (g_l.sb_idx < 32)
		{
			//write(1, "1", 1);
			g_l.sb[g_l.sb_idx++] = sign;
			if (g_l.sb_idx == 32)
				g_l.strlen = bin_to_dec(g_l.sb, 32);
		}
		else if (g_l.b_idx < 8)
		{
			//write(1, "3", 1);
			g_l.bin[g_l.b_idx++] = sign;
			if (g_l.b_idx == 8)
			{
				append_char(&g_l, bin_to_dec(g_l.bin, 8));
				ft_memset(&g_l.bin, 0, sizeof(int) * 8);
				g_l.b_idx = 0;
			}
		}
		printf("kk : %d\n", g_l.strlen);
		if (g_l.str != 0)
		{
			printf("gg : %d\n", (int)ft_strlen(g_l.str));
			printf("%s\n", g_l.str);
		}
		if (g_l.str != 0 && (int)ft_strlen(g_l.str) == g_l.strlen)
		{
			//write(1, "5", 1);
			write(1, g_l.str, ft_strlen(g_l.str));
			write(1, "\n", 1);
			free(g_l.str);
			g_l.str = 0;
			g_l.sb_idx = 0;
		}
	}
}

int main(void)
{
	char *pid = ft_itoa(getpid());

	//init
	ft_memset(&g_l, 0, sizeof(t_cllist));
	//g_l.str = NULL;

	write(1, "server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	signal(SIGUSR1, &proc);
	signal(SIGUSR2, &proc);
	while(1)
	{
		pause();
	}
	return 0;
}
