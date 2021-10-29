/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 08:39:12 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_minfo(int argc, char *argv[], t_minfo *minfo)
{
	int i;

	minfo->philo = ft_atoi(argv[1]);
	minfo->pinfo = (t_stat *)malloc(sizeof(t_pstat) * minfo->philo);
	minfo->finfo = (int *)malloc(sizeof(int) * minfo->philo);
	memset(minfo->pinfo, 0, sizeof(int) * minfo->philo);
	memset(minfo->finfo, 0, sizeof(int) * minfo->philo);	// not 0?
	pthread_mutex_init(&minfo->flag_mutex, NULL);
	minfo->mfork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * minfo->philo);
	i = -1;
	while (++i < minfo->philo)
		pthread_mutex_init(&minfo->mfork[i], NULL);
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

t_pstat	*init_pstat(t_pstat *pstat, t_minfo *minfo)
{
	int		i;

	pstat = (t_pstat *)malloc(sizeof(t_pstat) * minfo->philo);
	i = -1;
	while (++i < minfo->philo)
	{
		pstat[i].minfo = minfo;
		pstat[i].philo_num = (i + 1);
		pstat[i].dead_cnt = minfo->die;
		pstat[i].status = -1;
		pstat[i].eat_cnt = 0;
	}
	return (pstat);
}

// main thread
void	*monitor(void *arg)
{
	t_minfo			*minfo;
	
	int std = 0;

	minfo = (t_minfo *)arg;
	print_minfo(minfo);
	if (gettimeofday(&minfo->start, NULL) != 0)
	{
		write(2, "gettimeofday error\n", 20);
		exit(1);
	}
	while (1)
	{
		if (minfo->dflag != std)
		{
			printf("dflag : %d\n", minfo->dflag);
			std++;
			if (std == 1)
				return (NULL);
		}
	}
}

void	print_status(t_minfo *minfo, t_pstat *pstat)
{
	struct timeval	cur;
	int				time;

	if (gettimeofday(&cur, NULL) != 0)
	{
		write(2, "gettimeofday error\n", 20);
		exit(1);
	}
	time = (minfo->start.tv_sec * 1000 + minfo->start.tv_usec / 1000) - (cur.tv_sec * 1000 + cur.tv_usec / 1000);
	pthread_mutex_lock(&minfo->print_mutex);
	printf("%dms\t", time);
	if (pstat->status == -1)
		printf("%d not cycle !!!!!\n", pstat->philo_num);
	else if (pstat->status == EAT)
		printf("%dis eating\n", pstat->philo_num);
	else if (pstat->status == SLEEP)
		printf("%dis sleeping\n", pstat->philo_num);
	else if (pstat->status == THINK)
		printf("%dis thinking\n", pstat->philo_num);
	else if (pstat->status == DEAD)
		printf("%ddied\n", pstat->philo_num);
	else
	{
		printf("status error!\n");
		exit(1);
	}
	pthread_mutex_unlock(&minfo->print_mutex);
}

// philo thread
void	*philo_cycle(void *arg)
{
	int		i;
	t_pstat *pstat;

	pstat = (t_pstat *)arg;
	i = -1;

	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_minfo		minfo;
	t_pstat		*pstat;
	pthread_t	mt;

	// have to add input exception
	init_minfo(argc, argv, &minfo);
	pstat = NULL;
	pstat = init_pstat(pstat, &minfo);
	//print_minfo(&minfo);

	// thread create, detach
	pthread_create(&mt, NULL, &monitor, (void *)&minfo);
	
	i = -1;
	while (++i < minfo.philo)
		pthread_create(&minfo.pinfo[i].id, NULL, &philo_cycle, (void *)((t_pstat *)(pstat + i)));
	
	i = -1;
	while (++i < minfo.philo)
		pthread_detach(minfo.pinfo[i].id);
	pthread_join(mt, NULL);

	// mutex destroy
	i = -1;
	while (++i < minfo.philo)
		pthread_mutex_destroy(&minfo.mfork[i]);
	pthread_mutex_destroy(&minfo.flag_mutex);
	
	return (0);
}
