/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 18:50:34 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_minfo(int argc, char *argv[], t_minfo *minfo)
{
	struct timeval	start;
	int				i;

	minfo->philo = ft_atoi(argv[1]);
	minfo->pidinfo = (pthread_t *)malloc(sizeof(pthread_t) * minfo->philo);
	minfo->finfo = (int *)malloc(sizeof(int) * minfo->philo);
	memset(minfo->pidinfo, 0, sizeof(int) * minfo->philo);
	memset(minfo->finfo, 0, sizeof(int) * minfo->philo);	// not 0?
	pthread_mutex_init(&minfo->flag_mutex, NULL);
	pthread_mutex_init(&minfo->print_mutex, NULL);
	minfo->mfork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * minfo->philo);
	i = -1;
	while (++i < minfo->philo)
		pthread_mutex_init(&minfo->mfork[i], NULL);
	minfo->must_eat = -1;
	minfo->end = D_END;
	if (gettimeofday(&time, NULL) != 0)
		return (1);
	minfo->mtstart = cvt_time();
	minfo->err = 0;
	return (0);
}

void	init_pstat(int argc, char *argv[], t_minfo *minfo, t_pstat **pstat)
{
	int		i;

	*pstat = (t_pstat *)malloc(sizeof(t_pstat) * minfo->philo);
	i = -1;
	while (++i < minfo->philo)
	{
		*pstat[i]->minfo = minfo;
		*pstat[i]->philo_num = (i + 1);
		*pstat[i]->dead_cnt = ft_atoi(argv[2]);
		*pstat[i]->eat = ft_atoi(argv[3]);
		*pstat[i]->sleep = ft_atoi(argv[4]);
		minfo->think = 1;
		if ((*pstat[i].dead_cnt - minfo->eat - minfo->sleep - 1) < 0);
			minfo->think = 0;
		minfo->must_eat = -1;
		minfo->endflag = D_END;
		if (argc == 6)
		{
			minfo->must_eat = ft_atoi(argv[5]);
			minfo->endflag = M_END;
		}
		*pstat[i].status = -1;
		*pstat[i].eat_cnt = 0;
	}
}

// main thread
void	*monitor(void *arg)
{
	struct timeval	time;
	t_minfo			*minfo;
	
	minfo = (t_minfo *)arg;
	// print_minfo(minfo);
	if (gettimeofday(&time, NULL) != 0)
	{
		write(2, "gettimeofday error\n", 20);
		exit(1);
	}
	minfo->start = cvt_time(time);
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
	time = minfo->start - cvt_time(cur);
	pthread_mutex_lock(&minfo->print_mutex);
	printf("%dms\t", time);
	if (pstat->status == -1)
		printf("%d not cycle !!!!!\n", pstat->philo_num);
	else if (pstat->status == EAT)
		printf("%d is eating\n", pstat->philo_num);
	else if (pstat->status == SLEEP)
		printf("%d is sleeping\n", pstat->philo_num);
	else if (pstat->status == THINK)
		printf("%d is thinking\n", pstat->philo_num);
	else if (pstat->status == DEAD)
		printf("%d died\n", pstat->philo_num);
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
	t_pstat			*pstat;
	struct timeval	cur;

	pstat = (t_pstat *)arg;
	// EAT
	pstat->status = EAT;
	if (gettimeofday(&cur, NULL) != 0)
	{
		write(2, "gettimeofday error\n", 20);
		exit(1);
	}
	while (cvt_time(cur) < pstat->minfo->start + pstat->dead_cnt)
	{
		pstat->status = EAT;
		print_status(pstat->minfo, pstat);
		while (cvt_time(cur) < pstat->minfo->start + pstat->minfo->eat)
		{
			sleep(1);
			if (cvt_time(cur) >= pstat->minfo->start + pstat->dead_cnt)
			{
				pstat->status = DEAD;
				print_status(pstat->minfo, pstat);
				return (NULL);
			}
			if (gettimeofday(&cur, NULL) != 0)
			{
				write(2, "gettimeofday error\n", 20);
				exit(1);
			}
		}
		pstat->status = SLEEP;
		print_status(pstat->minfo, pstat);
		while (cvt_time(cur) < pstat->minfo->start + pstat->minfo->eat + pstat->minfo->sleep)
		{
			sleep(1);
			if (cvt_time(cur) >= pstat->minfo->start + pstat->dead_cnt)
			{
				pstat->status = DEAD;
				print_status(pstat->minfo, pstat);
				return (NULL);
			}
			if (gettimeofday(&cur, NULL) != 0)
			{
				write(2, "gettimeofday error\n", 20);
				exit(1);
			}
		}
		pstat->status = THINK;
		print_status(pstat->minfo, pstat);
		sleep(1);
		if (cvt_time(cur) >= pstat->minfo->start + pstat->dead_cnt)
		{
			pstat->status = DEAD;
			print_status(pstat->minfo, pstat);
			return (NULL);
		}
	}
	pstat->status = DEAD;
	print_status(pstat->minfo, pstat);
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
	pthread_mutex_destroy(&minfo.print_mutex);
	
	return (0);
}
