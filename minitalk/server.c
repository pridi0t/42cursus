#include "server.h"
#include <stdio.h>

t_cllist *g_l;

void proc(int signum, siginfo_t *info, void *oact)
{
	//printf("signo :%d\n", signum);
	char *pid = ft_itoa(info->si_pid);
	//t_cllist *l = NULL;

	if (signum == SIGUSR1 || signum == SIGUSR2)
	{
		write(1, "client PID : ", 13);
		write(1, pid, ft_strlen(pid));
		write(1, "\n", 2);	
		if (search(info->si_pid) == 0)
		{
			add_last(info->si_pid);
			print_list();
			//printf("after : ");
			//(void)signum;
			return ;
		}
		printf("exist pid\n");
	}
	//(void)signum;
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
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return 0;
}
