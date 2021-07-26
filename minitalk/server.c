/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:08:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/07/26 11:32:12 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_i;

int	bin_to_dec(int bin[], int blen)
{
	int	i;
	int	base;
	int	result;

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

void	append_char(t_info *i, int c)
{
	if (i->str == NULL)
	{
		i->str = (char *)malloc(i->strlen);
		ft_memset(i->str, 0, i->strlen);
		i->str_idx = 0;
	}
	i->str[i->str_idx++] = (char)c;
}

void	check_str(void)
{
	if (g_i.str != 0 && (int)ft_strlen(g_i.str) == g_i.strlen)
	{
		write(1, g_i.str, ft_strlen(g_i.str));
		write(1, "\n", 1);
		free(g_i.str);
		g_i.str = 0;
		g_i.sb_idx = 0;
	}
}

void	proc(int signum)
{
	int	sign;

	sign = 0;
	if (signum == SIGUSR1)
		sign = 1;
	if (g_i.sb_idx < 32)
	{
		g_i.sb[g_i.sb_idx++] = sign;
		if (g_i.sb_idx == 32)
			g_i.strlen = bin_to_dec(g_i.sb, 32);
	}
	else if (g_i.b_idx < 8)
	{
		g_i.bin[g_i.b_idx++] = sign;
		if (g_i.b_idx == 8)
		{
			append_char(&g_i, bin_to_dec(g_i.bin, 8));
			ft_memset(&g_i.bin, 0, sizeof(int) * 8);
			g_i.b_idx = 0;
		}
	}
	check_str();
}

int	main(void)
{
	char	*pid;

	pid = ft_itoa(getpid());
	ft_memset(&g_i, 0, sizeof(t_info));
	write(1, "server PID : ", 13);
	write(1, pid, ft_strlen(pid));
	write(1, "\n", 2);
	signal(SIGUSR1, &proc);
	signal(SIGUSR2, &proc);
	while (1)
		pause();
	return (0);
}
