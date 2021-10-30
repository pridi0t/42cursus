/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 02:33:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_minfo(char *argv[], t_minfo *minfo)
{
	int	i;

	minfo->philo = ft_atoi(argv[1]);
	minfo->pidinfo = (t_pidinfo *)malloc(sizeof(t_pidinfo) * minfo->philo);
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
	minfo->dead = 0;
	minfo->end = D_END;
	minfo->start = 0;
	if (minfo->start == -1)
		return (1);
	minfo->err = 0;
	return (0);
}

t_pstat	*init_pstat(int argc, char *argv[], t_minfo *minfo, t_pstat *pstat)
{
	int		i;

	pstat = (t_pstat *)malloc(sizeof(t_pstat) * minfo->philo + 1);
	if (argc == 6)
	{
		minfo->must_eat = ft_atoi(argv[5]);
		minfo->end = E_END;
	}
	i = -1;
	while (++i < minfo->philo)
	{
		pstat[i].minfo = minfo;
		pstat[i].philo_num = (i + 1);
		pstat[i].dead_cnt = ft_atoi(argv[2]);
		pstat[i].eat = ft_atoi(argv[3]);
		pstat[i].sleep = ft_atoi(argv[4]);
		pstat[i].status = -1;
		pstat[i].start = 0;
		pstat[i].think = pstat[i].dead_cnt - pstat[i].eat - pstat[i].sleep;
		if (pstat[i].think <= 0)
			pstat[i].think = 0;
	}
	return (pstat);
}

// main thread
void	*monitor(void *arg)
{
	t_minfo	*minfo;
	int		i;

	minfo = (t_minfo *)arg;
	// print_minfo(minfo);
	minfo->start = get_time();
	if (minfo->start == -1)
	{
		minfo->err = 1;
		return (NULL);
	}
	while (1)
	{
		if (minfo->dead == 1)
			return (NULL);
		if (minfo->end == E_END && minfo->must_eat != -1)
		{
			i = -1;
			while ((minfo->pidinfo[i].eat_cnt >= minfo->must_eat) && (++i < minfo->philo))
				i++;
			if (i == minfo->philo)
				return (NULL);
		}
	}
}

int	print_status(t_minfo *minfo, t_pstat *pstat)
{
	int cur;

	cur = get_time();
	pthread_mutex_lock(&minfo->print_mutex);
	printf("%dms\t", cur - minfo->start);
	if (pstat->status == EAT)
		printf("%d is eating\n", pstat->philo_num);
	else if (pstat->status == SLEEP)
		printf("%d is sleeping\n", pstat->philo_num);
	else if (pstat->status == THINK)
		printf("%d is thinking\n", pstat->philo_num);
	else if (pstat->status == DEAD)
		printf("%d died\n", pstat->philo_num);
	else
	{
		print_err(minfo, 2);
		return (-1);
	}
	pthread_mutex_unlock(&minfo->print_mutex);
	return (0);
}

// philo thread
void	*philo_cycle(void *arg)
{
	t_pstat	*pstat;
	int		cur;

	pstat = (t_pstat *)arg;
	if (pstat->think == 0)
	{
		pthread_mutex_lock(&pstat->minfo->flag_mutex);
		pstat->status = DEAD;
		print_status(pstat->minfo, pstat);
		pstat->minfo->dead++;
		pthread_mutex_unlock(&pstat->minfo->flag_mutex);
		return (NULL);
	}
	cur = get_time();
	pstat->start = cur;
	while (cur - pstat->start < pstat->dead_cnt)
	{
		// EAT
		pstat->status = EAT;
		print_status(pstat->minfo, pstat);
		pstat->minfo->pidinfo[pstat->philo_num - 1].eat_cnt++;
		while (cur - pstat->start <= pstat->eat)
		{
			usleep(1);
			cur = get_time();
			if (cur - pstat->start >= pstat->dead_cnt)
			{
				pthread_mutex_lock(&pstat->minfo->flag_mutex);
				pstat->status = DEAD;
				print_status(pstat->minfo, pstat);
				pstat->minfo->dead++;
				pthread_mutex_unlock(&pstat->minfo->flag_mutex);
				return (NULL);
			}
		}
		// SLEEP
		cur = get_time();
		pstat->status = SLEEP;
		print_status(pstat->minfo, pstat);
		while (cur - (pstat->start + pstat->eat) <= pstat->sleep)
		{
			usleep(1);
			cur = get_time();
			if (cur - pstat->start >= pstat->dead_cnt)
			{
				pthread_mutex_lock(&pstat->minfo->flag_mutex);
				pstat->status = DEAD;
				print_status(pstat->minfo, pstat);
				pstat->minfo->dead++;
				pthread_mutex_unlock(&pstat->minfo->flag_mutex);
				return (NULL);
			}
		}
		// THINK
		cur = get_time();
		pstat->status = THINK;
		print_status(pstat->minfo, pstat);
		while (cur - (pstat->start + pstat->eat + pstat->sleep + 1) != 0)
		{
			usleep(1);
			cur = get_time();
		}
		if (cur - pstat->start >= pstat->dead_cnt)
			break;
		cur = get_time();
		pstat->start = cur;
	}
	pthread_mutex_lock(&pstat->minfo->flag_mutex);
	pstat->status = DEAD;
	print_status(pstat->minfo, pstat);
	pstat->minfo->dead++;
	pthread_mutex_unlock(&pstat->minfo->flag_mutex);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	int			i;
	t_minfo		minfo;
	t_pstat		*pstat;
	pthread_t	mt;

	// have to add input exception
	if (init_minfo(argv, &minfo) == 1)
		return (1);
	pstat = NULL;
	pstat = init_pstat(argc, argv, &minfo, pstat);
	if (pstat == NULL)
		return (1);
	/*
	print_minfo(&minfo);
	i = -1;
	while (++i < minfo.philo)
		print_pstat(&pstat[i]);
	*/

	// thread create, detach
	pthread_create(&mt, NULL, &monitor, (void *)&minfo);
	
	i = -1;
	while (++i < minfo.philo)
		pthread_create(&minfo.pidinfo[i].pid, NULL, &philo_cycle, (void *)(pstat + i));
	
	i = -1;
	while (++i < minfo.philo)
		pthread_detach(minfo.pidinfo[i].pid);
	pthread_join(mt, NULL);
	//free_data(&minfo, &pstat);
	return (0);
}
