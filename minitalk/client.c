/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:28:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/07/26 11:44:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	dec_to_bin(int *bin, int n)
{
	int	i;
	int	num;

	i = 0;
	num = n;
	while (num != 0)
	{
		bin[i++] = num % 2;
		num /= 2;
	}
}

void	send_strlen(int pid, char *argv)
{
	int	i;
	int	slen[32];

	ft_memset(slen, 0, sizeof(slen));
	dec_to_bin(slen, ft_strlen(argv));
	i = (int)(sizeof(slen) / sizeof(int));
	while (--i >= 0)
	{
		if (slen[i] == 1)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

void	send_str(int pid, int len, char *argv)
{
	int	i;
	int	j;
	int	bin[8];

	i = -1;
	while (++i < len)
	{
		ft_memset(bin, 0, sizeof(bin));
		dec_to_bin(bin, argv[i]);
		j = 8;
		while (--j >= 0)
		{
			if (bin[j] == 1)
			{
				kill(pid, SIGUSR1);
				usleep(50);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}	
		}
	}
}

int	main(int argc, char *argv[])
{
	char	*pid;

	if (argc != 3)
	{
		write(2, "invalid argument\n", 18);
		return (0);
	}
	pid = ft_itoa(getpid());
	write(1, "PID : ", 6);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	free(pid);
	send_strlen(ft_atoi(argv[1]), argv[2]);
	send_str(ft_atoi(argv[1]), (int)ft_strlen(argv[2]), argv[2]);
	return (0);
}
