#include <unistd.h>
#include "libft.h"
#include <signal.h>

#include <stdio.h>

void dec_to_bin(int *bin, char c)
{
	int i;
	int num;

	i = 0;
	num = c;
	while (num != 0)
	{
		bin[i++] = num % 2;
		num /= 2;
	}
}

int main(int argc, char *argv[])
{
	siginfo_t set;
	char *str;
	int bin[8];
	int slen[32];
	int i;
	int j;
	
	if (argc != 3)
	{
		write(2, "invalid argument\n", 18);
		return (0);
	}
	set.si_pid = getpid();
	str = ft_itoa(set.si_pid);
	write(1, "PID : ", 6);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);

	// send strlen
	ft_memset(slen, 0, sizeof(slen));
	dec_to_bin(slen, ft_strlen(argv[2]));
	i = (int)(sizeof(slen) / sizeof(int));
	while (--i >= 0)
	{
		if (slen[i] == 1)
		{
			kill(ft_atoi(argv[1]), SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(ft_atoi(argv[1]), SIGUSR2);
			usleep(100);
		}
	}

	// send str
	i = (int)ft_strlen(argv[2]);
	while (--i >= 0)
	{
		ft_memset(bin, 0, sizeof(bin));
		dec_to_bin(bin, argv[2][i]);
		j = 8;
		while (--j >= 0)
		{
			if (bin[j] == 1)
			{
				kill(ft_atoi(argv[1]), SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(ft_atoi(argv[1]), SIGUSR2);
				usleep(100);
			}	
		}
		printf("\n");
	}
	//kill(ft_atoi(argv[1]), SIGUSR1);
	return 0;
}
