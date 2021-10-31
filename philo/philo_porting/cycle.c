/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 09:03:44 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 19:53:36 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_pinfo *parr, t_minfo *minfo)
{
	if ((parr->idx % 2) == 0)
		pthread_mutex_lock(parr->l_hand);
	else
		pthread_mutex_lock(parr->r_hand);
	print_status(parr, minfo, "has taken fork\n");
	if (minfo->philo == 1)
	{
		ms_sleep(minfo->dead_cnt + 100);
		pthread_mutex_unlock(parr->l_hand);
		return ;
	}
	if ((parr->idx % 2) == 0)
		pthread_mutex_lock(parr->r_hand);
	else
		pthread_mutex_lock(parr->l_hand);
	print_status(parr, minfo, "has taken fork\n");
	print_status(parr, minfo, "is eating\n");
	(parr->eat_cnt)++;
	parr->last_eat = get_time();
	ms_sleep(minfo->eat);
	pthread_mutex_unlock(parr->l_hand);
	pthread_mutex_unlock(parr->r_hand);
}

void	philo_sleep(t_pinfo *parr, t_minfo *minfo)
{
	if (minfo->dead != -1)
		return ;
	print_status(parr, minfo, "is sleeping\n");
	ms_sleep(minfo->sleep);
	print_status(parr, minfo, "is thinking\n");
}

void	*cycle(void *arg)
{
	t_pinfo	*parr;
	t_minfo	*minfo;

	parr = (t_pinfo *)arg;
	minfo = parr->minfo;
	while (minfo->dead == -1 && minfo->end == 0)
	{
		philo_eat(parr, minfo);
		philo_sleep(parr, minfo);
	}
	return (NULL);
}

void	start_cycle(t_minfo *minfo)
{
	int	i;

	if (pthread_create(&minfo->mt, 0, &monitor, (void *)minfo))
		minfo->err = 1;
	i = -1;
	while (++i < minfo->philo)
		if ((i % 2) == 0)
			if (pthread_create(&minfo->parr[i].pt, NULL, \
						&cycle, (void *)&minfo->parr[i]))
				minfo->err = 1;
	i = 0;
	while (++i < minfo->philo)
		if ((i % 2) != 0)
			if (pthread_create(&minfo->parr[i].pt, NULL, \
						&cycle, (void *)&minfo->parr[i]))
				minfo->err = 1;
	if (minfo->err == 1)
		print_err(3);
}
