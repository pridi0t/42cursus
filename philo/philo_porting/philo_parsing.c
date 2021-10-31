/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 07:09:19 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 12:16:07 by hyojang          ###   ########.fr       */
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

int	check_arg(int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

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

int	parse_arg(int argc, char *argv[], t_minfo *minfo)
{
	if (check_arg(argc, argv) == 1)
		return (1);
	tminfo->philo = ft_atoi(argv[1]);
	tminfo->dead_cnt = ft_atoi(argv[2]);
	tminfo->eat = ft_atoi(argv[3]);
	tminfo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		tminfo->must_eat = ft_atoi(argv[5]);
	return (0);
}
