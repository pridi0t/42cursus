#include "server.h"

void handler(int signum, siginfo_t *info, void *addr)
{
	char *pid = ft_itoa(info->si_pid);
	char *str = (char *)info->si_addr;

	if (signum == SIGUSR1)
	{
		write(1, "client PID : ", 13);
		write(1, pid, ft_strlen(pid));
		write(1, "\nmessage : ", 12);
		write(1, "\n", 2);
	}
}

int main(void)
{
	struct sigaction act;
	char *pid = ft_itoa(getpid());
	
	/*
	write(1, "server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	act.sa_sigaction = handler;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		usleep(100);
	}
	*/
	t_cllist *l;
	add_last(&l, 1);
	add_last(&l, 2);
	add_last(&l, 3);
	add_last(&l, 4);
	add_last(&l, 5);
	t_cllist *p = l;
	while (p->link != l)
	{
		ft_strlcpy(p->str, "aa", 2);
		p = p->link;
	}
	print_list(l);
	return 0;
}
