/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/28 07:06:25 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_pstat {
	int	id;
	int	status;
} t_stat;

typedef struct s_pstat {
	int eat;
	int sleep;
	int think;
	int cnt;
	int status;
} t_pstat;

void	cycle(void *arg)
{
	t_pstat stat;

	ft_memcpy(stat, arg, sizeof(stat));

}

int	main(int argc, char *argv[])
{
	t_stat	*pinfo;
	int		*finfo;
	int		philo;
	int		nfork;
	int		dead_num = 0;

	t_pstat = pstat;
	int	die;
	int	must_eat; 
	
	philo = ft_atoi(argv[1]);
	nfork = philo;
	pinfo = (int *)malloc(sizeof(t_stat) * philo);
	finfo = (int *)malloc(sizeof(int) * nfork);
	memset(pinfo, 0, sizeof(int) * philo);
	memset(finfo, 0, sizeof(int) * nfork);	// not 0?

	die = ft_atoi(argv[2]);
	pstat.eat = ft_atoi(argv[3]);
	pstat.sleep = ft_atoi(argv[4]);
	pstat.think = die - eat - sleep;
	if (pstat.think < 0)
		pstat.think = 0;
	must_eat = 0;
	if (argc == 6)
		must_eat = ft_atoi(argv[5]);

	pthread_create()

	return (0);
}
