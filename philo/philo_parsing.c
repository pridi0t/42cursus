/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 07:09:19 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 07:44:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_input(int argc, char *argv[])
{
	int i;
	int j;
	int flag;

	if (argc != 5 && argc != 6)
		return (1);
	flag = 0;
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j] != 0)
		{
			if (ft_isdigit(argv[i][j]) != 1)
				return (1);
		}
		if (ft_atoi(argv[i]) <= 0 || ft_atoi(argv[i]) > 10000)
			return (1);
	}
	if (ft_atoi(argv[1]) > 200)
		return (1);
	return (0);
}
