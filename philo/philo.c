/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 10:27:15 by hyojang          ###   ########.fr       */
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
	if (init_minfo(argv, &minfo) == -1)
	{
		print_err(2);
		return (1);
	}
	pstat = NULL;
	pstat = init_pstat(argc, argv, &minfo, pstat);
	if (pstat == NULL)
	{
		// free_minfo
		print_err(2);
		return (1);
	}
	pthread_create(&mt, NULL, &monitor, (void *)&minfo);
	i = -1;
	while (++i < minfo.philo)
		pthread_create(&minfo.pidinfo[i].pid, NULL, &philo_cycle, (void *)(pstat + i));
	i = -1;
	while (++i < minfo.philo)
		pthread_join(minfo.pidinfo[i].pid, NULL);
	pthread_join(mt, NULL);
	//free_data(&minfo, &pstat);
	return (0);
}
