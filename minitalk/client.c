#include <unistd.h>
#include "libft.h"
#include <signal.h>

int main(int argc, char *argv[])
{
	siginfo_t set;
	char *str;
	
	/*
	if (argc != 3)
	{
		write(2, "invalid argument\n", 18);
		return (0);
	}
	*/
	set.si_pid = getpid();
	str = ft_itoa(set.si_pid);
	set.si_addr = argv[2];
	write(1, "PID : ", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	kill(ft_atoi(argv[1]), SIGUSR1);
	return 0;
}
