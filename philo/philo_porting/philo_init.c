/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 03:01:51 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 20:32:31 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_pinfo(t_minfo *minfo)
{
	int	i;

	minfo->parr = malloc(sizeof(t_pinfo) * minfo->philo);
	minfo->mfork = malloc(sizeof(pthread_mutex_t) * minfo->philo);
	if (minfo->parr == 0 || minfo->mfork == 0)
		return (-1);
	minfo->start = get_time();
	minfo->dead = -1;
	if (minfo->must_eat == 0)
		minfo->must_eat = -1;
	i = -1;
	while (++i < minfo->philo)
	{
		memset(&minfo->parr[i], 0, sizeof(t_pinfo));
		minfo->parr[i].idx = i;
		minfo->parr[i].last_eat = minfo->start;
		minfo->parr[i].minfo = minfo;
	}
	return (0);
}

int	init_mutex(t_minfo *minfo)
{
	int	i;

	i = -1;
	while (++i < minfo->philo)
	{
		if (pthread_mutex_init(&minfo->mfork[i], NULL) != 0)
			return (-1);
		minfo->parr[i].l_hand = &minfo->mfork[i];
		minfo->parr[i].r_hand = &minfo->mfork[(i + 1) % minfo->philo];
	}
	if (pthread_mutex_init(&minfo->print, 0))
		return (-1);
	return (0);
}

int	init_all(int argc, char *argv[], t_minfo *minfo)
{
	if (parse_arg(argc, argv, minfo) == 1)
	{
		print_err(0);
		return (-2);
	}
	else if (init_pinfo(minfo) == -1)
		print_err(1);
	else if (init_mutex(minfo) == -1)
		print_err(2);
	else
		return (1);
	return (-1);
}

void	free_all(t_minfo *minfo)
{
	int	i;

	pthread_join(minfo->mt, NULL);
	i = -1;
	while (++i < minfo->philo)
		pthread_join(minfo->parr[i].pt, NULL);
	i = -1;
	while (++i < minfo->philo)
		pthread_mutex_destroy(&minfo->mfork[i]);
	free(minfo->parr);
	free(minfo->mfork);
}
