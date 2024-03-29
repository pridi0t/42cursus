/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 03:01:51 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 11:01:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_minfo(char *argv[], t_minfo *minfo)
{
	int	i;

	minfo->philo = ft_atoi(argv[1]);
	minfo->pidinfo = (t_pidinfo *)malloc(sizeof(t_pidinfo) * minfo->philo);
	if (minfo->pidinfo == NULL)
		return (-1);
	memset(minfo->pidinfo, 0, sizeof(t_pidinfo) * minfo->philo);
	pthread_mutex_init(&minfo->flag_mutex, NULL);
	pthread_mutex_init(&minfo->print_mutex, NULL);
	minfo->mfork = (pthread_mutex_t \
			*)malloc(sizeof(pthread_mutex_t) * minfo->philo);
	if (minfo->mfork == NULL)
		return (-1);
	i = -1;
	while (++i < minfo->philo)
		pthread_mutex_init(&minfo->mfork[i], NULL);
	minfo->must_eat = -1;
	minfo->dead = 0;
	minfo->end = D_END;
	minfo->start = 0;
	minfo->err = 0;
	return (0);
}

t_pstat	*init_pstat(int argc, char *argv[], t_minfo *minfo, t_pstat *pstat)
{
	int		i;

	pstat = (t_pstat *)malloc(sizeof(t_pstat) * minfo->philo);
	if (pstat == NULL)
		return (pstat);
	if (argc == 6)
	{
		minfo->must_eat = ft_atoi(argv[5]);
		minfo->end = E_END;
	}
	i = -1;
	while (++i < minfo->philo)
	{
		pstat[i].minfo = minfo;
		pstat[i].philo_num = i;
		pstat[i].dead_cnt = ft_atoi(argv[2]);
		pstat[i].start = 0;
		pstat[i].eat = ft_atoi(argv[3]);
		pstat[i].sleep = ft_atoi(argv[4]);
		pstat[i].think = pstat[i].dead_cnt - pstat[i].eat - pstat[i].sleep;
		if (pstat[i].think <= 0)
			pstat[i].think = 0;
		else
			pstat[i].think = 1;
	}
	return (pstat);
}
