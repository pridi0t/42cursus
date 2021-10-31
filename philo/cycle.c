/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:03:44 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 11:15:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_minfo *minfo, t_pstat *pstat)
{
	if (minfo->philo == 1)
		return (0);
	if (pstat->philo_num % 2 == 0)
	{
		pthread_mutex_lock(&minfo->mfork[pstat->philo_num]);
		print_status(pstat->minfo, pstat, G_FORK);
		pthread_mutex_lock(&minfo->mfork[(pstat->philo_num + 1) % minfo->philo]);
		print_status(pstat->minfo, pstat, G_FORK);
	}
	else
	{
		pthread_mutex_lock(&minfo->mfork[(pstat->philo_num + 1) % minfo->philo]);
		print_status(pstat->minfo, pstat, G_FORK);
		pthread_mutex_lock(&minfo->mfork[pstat->philo_num]);
		print_status(pstat->minfo, pstat, G_FORK);
	}
	if (pstat->dead_cnt <= pstat->eat)
	{
		pthread_mutex_unlock(&minfo->mfork[pstat->philo_num]);
		pthread_mutex_unlock(&minfo->mfork[(pstat->philo_num + 1) % minfo->philo]);
		return (0);
	}
	print_status(pstat->minfo, pstat, EAT);
	ms_sleep(pstat->eat);
	pthread_mutex_unlock(&minfo->mfork[pstat->philo_num]);
	pthread_mutex_unlock(&minfo->mfork[(pstat->philo_num + 1) % minfo->philo]);
	return (1);
}

int	check_die(t_pstat *pstat)
{
	int	i;

	i = -1;
	while (++i < pstat->philo_num)
	{
		if (pstat->minfo->pidinfo[i].status == 0)
			return (1);
	}
	return (0);
}

void	*philo_cycle(void *arg)
{
	t_pstat	*pstat;

	pstat = (t_pstat *)arg;
	pstat->start = get_time();
	pstat->minfo->pidinfo[pstat->philo_num].status = 1;
	if (pstat->think == 0)
	{
		print_status(pstat->minfo, pstat, DEAD);
		return (NULL);
	}
	while (get_time() - pstat->start < pstat->dead_cnt)
	{
		if (eat(pstat->minfo, pstat) != 1)
			break ;
		if ((pstat->dead_cnt - pstat->eat) > pstat->sleep)
		{
			print_status(pstat->minfo, pstat, SLEEP);
			ms_sleep(pstat->sleep);
		}
		else
			break ;
		if ((pstat->dead_cnt - pstat->eat - pstat->sleep) > 1)
		{
			print_status(pstat->minfo, pstat, THINK);
			ms_sleep(1);
		}
		else
			break ;
		pstat->start = get_time();
	}
	print_status(pstat->minfo, pstat, DEAD);
	return (NULL);
}
