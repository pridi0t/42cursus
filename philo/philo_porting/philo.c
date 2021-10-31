/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 20:01:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cnt_ate(t_minfo *minfo)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = -1;
	while (++i < minfo->philo)
	{
		if (minfo->parr[i].eat_cnt >= minfo->must_eat)
			cnt++;
	}
	return (cnt);
}

void	*print_die(t_minfo *minfo, long long cur, int i)
{
	pthread_mutex_lock(&minfo->print);
	minfo->dead = i;
	printf("%lld %d died\n", cur - minfo->start, i + 1);
	pthread_mutex_unlock(&minfo->print);
	return (NULL);
}

void	*monitor(void *arg)
{
	t_minfo		*minfo;
	long long	cur;
	int			i;

	minfo = (t_minfo *)arg;
	while (minfo->dead < 0)
	{
		i = -1;
		while (++i < minfo->philo)
		{
			cur = get_time();
			if ((minfo->must_eat != -1) && cnt_ate(minfo) == minfo->philo)
			{
				minfo->end = 1;
				return (NULL);
			}
			if ((cur - minfo->parr[i].last_eat) <= minfo->dead_cnt)
				continue ;
			return (print_die(minfo, cur, i));
		}
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_minfo		minfo;
	int			flag;

	memset(&minfo, 0, sizeof(t_minfo));
	flag = init_all(argc, argv, &minfo);
	if (flag == 1)
		start_cycle(&minfo);
	free_all(&minfo);
	return (0);
}
