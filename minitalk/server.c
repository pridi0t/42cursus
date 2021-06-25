#include <unistd.h>
#include <signal.h>
#include "libft.h"

void handler(int signum, siginfo_t *info, void *addr)
{
	char *pid = ft_itoa(info->si_pid);
	char *str = (char *)info->si_addr;

	if (signum == SIGUSR1)
	{
		write(1, "client PID : ", 13);
		write(1, pid, ft_strlen(pid));
		write(1, "\nmessage : ", 12);
		write(1, str, ft_strlen(str));
	}
}

int main(void)
{
	struct sigaction act;
	char *pid = ft_itoa(getpid());
	
	write(1, "server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	act.sa_sigaction = handler;
	while(1)
	{
		sigaction(SIGUSR1, &act, 0);
	}
	return 0;
}
