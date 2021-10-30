/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 05:55:23 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// main thread
void	*monitor(void *arg)
{
	t_minfo	*minfo;
	int		i;

	minfo = (t_minfo *)arg;
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

int	acc_finfo(t_minfo *minfo, int philo_num, int value)
{
	pthread_mutex_lock(&minfo->acc_mutex);
	if (value == 1)
	{
		if (minfo->finfo[philo_num] == 0 && minfo->finfo[philo_num + 1] == 0)
		{
			minfo->finfo[philo_num] = 1;
			minfo->finfo[(philo_num + 1) % minfo->philo] = 1;
			pthread_mutex_unlock(&minfo->acc_mutex);
			return (1);
		}
		pthread_mutex_unlock(&minfo->acc_mutex);
		return (-1);
	}
	minfo->finfo[philo_num] = 0;
	minfo->finfo[(philo_num + 1) % minfo->philo] = 0;
	pthread_mutex_unlock(&minfo->acc_mutex);
	return (1);
}

int	eat(t_minfo *minfo, t_pstat *pstat)
{
	//edit db, set mutex
	if (acc_finfo(minfo, pstat->philo_num, 1) == 1)
	{
		pthread_mutex_lock(&minfo->mfork[pstat->philo_num]);
		pthread_mutex_lock(&minfo->mfork[(pstat->philo_num + 1) % pstat->philo_num]);
		print_status(pstat->minfo, pstat->philo_num, G_FORK);
		print_status(pstat->minfo, pstat->philo_num, EAT);
		if (pstat->dead_cnt <= pstat->eat)
		{
			pthread_mutex_unlock(&minfo->mfork[pstat->philo_num]);
			pthread_mutex_unlock(&minfo->mfork[(pstat->philo_num + 1) % pstat->philo_num]);
			return (0);
		}
		ms_sleep(pstat->eat);
		pthread_mutex_unlock(&minfo->mfork[pstat->philo_num]);
		pthread_mutex_unlock(&minfo->mfork[(pstat->philo_num + 1) % pstat->philo_num]);
		return (1);
	}		
	if (acc_finfo(minfo, pstat->philo_num, 0) != 1)
		return (0);
	return (1);
}

// philo thread
void	*philo_cycle(void *arg)
{
	t_pstat	*pstat;

	pstat = (t_pstat *)arg;
	if (pstat->think == 0)
	{
		print_status(pstat->minfo, pstat->philo_num, DEAD);
		return (NULL);
	}
	pstat->start = get_time();
	while (get_time() - pstat->start < pstat->dead_cnt)
	{
		// EAT
		if (eat(pstat->minfo, pstat) == 0)
			break;
		// SLEEP
		print_status(pstat->minfo, pstat->philo_num, SLEEP);
		if ((pstat->dead_cnt - pstat->eat) > pstat->sleep)
			ms_sleep(pstat->sleep);
		else
			break;
		// THINK
		print_status(pstat->minfo, pstat->philo_num, THINK);
		if ((pstat->dead_cnt - pstat->eat - pstat->sleep) > 1)
			ms_sleep(1);
		else
			break;
		pstat->start = get_time();
	}
	print_status(pstat->minfo, pstat->philo_num, DEAD);
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
	pthread_create(&mt, NULL, &monitor, (void *)&minfo);
	i = -1;
	while (++i < minfo.philo)
		pthread_create(&minfo.pidinfo[i].pid, NULL, &philo_cycle, (void *)(pstat + i));
	i = -1;
	while (++i < minfo.philo)
		pthread_detach(minfo.pidinfo[i].pid);
	pthread_join(mt, NULL);
	// memory free
	//free_data(&minfo, &pstat);
	return (0);
}
