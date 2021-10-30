/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 07:41:55 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		i = -1;
		while (++i < minfo->philo)
		{
			if (minfo->pidinfo[i].status == 0)
			{
				i = -1;
				while (++i < minfo->philo)
					minfo->pidinfo[i].status = 0;
				return (NULL);
			}
		}
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

int	eat(t_minfo *minfo, t_pstat *pstat)
{
	if (pstat->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&minfo->mfork[pstat->philo_num]);
		print_status(pstat->minfo, pstat->philo_num, G_FORK);
		pthread_mutex_lock(&minfo->mfork[(pstat->philo_num + 1) % pstat->philo_num]);
		print_status(pstat->minfo, pstat->philo_num, G_FORK);
	}
	else
	{
		pthread_mutex_lock(&minfo->mfork[(pstat->philo_num + 1) % pstat->philo_num]);
		print_status(pstat->minfo, pstat->philo_num, G_FORK);
		pthread_mutex_lock(&minfo->mfork[pstat->philo_num]);
		print_status(pstat->minfo, pstat->philo_num, G_FORK);
	}
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

int	check_die(t_pstat *pstat)
{
	int i;

	i = -1;
	while (++i < pstat->philo_num)
	{
		if (pstat->minfo->pidinfo[i].status == 0)
			return (1);
	}
	return (0);
}

// philo thread
void	*philo_cycle(void *arg)
{
	t_pstat	*pstat;

	pstat = (t_pstat *)arg;
	pstat->minfo->pidinfo[pstat->philo_num].status = 1;
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
		if ((pstat->dead_cnt - pstat->eat - pstat->sleep) >= 1)
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

	if (check_input(argc, argv) == 1)
	{
		print_err(0);
		return (1);
	}
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
		pthread_join(minfo.pidinfo[i].pid, NULL);
	pthread_join(mt, NULL);
	// memory free
	//free_data(&minfo, &pstat);
	return (0);
}
