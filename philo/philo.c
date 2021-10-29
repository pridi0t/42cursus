/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 04:51:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_minfo(int argc, char *argv[], t_minfo *minfo)
{
	minfo->philo = ft_atoi(argv[1]);
	//minfo->nfork = philo;
	minfo->pinfo = (t_stat *)malloc(sizeof(t_pstat) * minfo->philo);
	minfo->finfo = (int *)malloc(sizeof(int) * minfo->philo);
	memset(minfo->pinfo, 0, sizeof(int) * minfo->philo);
	memset(minfo->finfo, 0, sizeof(int) * minfo->philo);	// not 0?

	minfo->eat = ft_atoi(argv[3]);
	minfo->sleep = ft_atoi(argv[4]);
	minfo->die = ft_atoi(argv[2]);
	minfo->think = minfo->die - minfo->eat - minfo->sleep;
	if (minfo->think < 0)
		minfo->think = 0;
	minfo->must_eat = 0;
	if (argc == 6)
		minfo->must_eat = ft_atoi(argv[5]);
	minfo->dflag = 0;
}

// main thread
void	*monitor(void *arg)
{
	struct timeval	start;
	struct timeval	cur;
	int				gap;
	t_minfo			*minfo;

	minfo = (t_minfo *)arg;
	print_minfo(minfo);
	if (gettimeofday(&start, NULL) != 0)
	{
		write(2, "time error\n", 11);
		exit(1);
	}
	while (1)
	{
		if (gettimeofday(&cur, NULL) != 0)
		{
			write(2, "time error\n", 11);
			exit(1);
		}
		gap = (cur.tv_sec * 1000 + cur.tv_usec / 1000) - (start.tv_sec * 1000 + start.tv_usec / 1000);
		if (gap >= 50)
			return (NULL);
		printf("%dms\n", gap);
		usleep(1000);
	}
}

// philo thread
void	*philo_cycle(void *arg)
{
	t_pstat pstat;
	t_minfo	*minfo;

	minfo = (t_minfo *)arg;
	pstat.dead_cnt = minfo->die;
	pstat.status = -1;
	pstat.eat_cnt = 0;

	
}

int	main(int argc, char *argv[])
{
	int			i;
	t_minfo		minfo;
	pthread_t	m;

	// have to add input exception
	init_minfo(argc, argv, &minfo);
	//print_minfo(&minfo);

	pthread_create(&m, NULL, &monitor, (void *)&minfo);
	i = -1;
	while (++i < minfo.philo)
	{
		pthread_create(minfo.pinfo[i].id, NULL, );
	}
	pthread_join(m, NULL);
	
	return (0);
}
