/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:54:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 19:19:41 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ms_sleep(int ms)
{
	long long	goal;
	long long	sleep_time;

	goal = get_time() + ms;
	while (goal > get_time())
	{
		sleep_time = (goal - get_time()) / 2;
		if ((long long)100 > sleep_time)
			usleep(100);
		else
			usleep(sleep_time);
	}
}

void	print_err(int errnum)
{
	if (errnum == 0)
		write(2, "arg error\n", 10);
	else if (errnum == 1)
		write(2, "malloc error\n", 13);
	else if (errnum == 2)
		write(2, "mutex error\n", 12);
	else if (errnum == 3)
		write(2, "thread create err\n", 18);
	else if (errnum == 4)
		write(2, "gettimeofday error\n", 19);
}

void	print_status(t_pinfo *parr, t_minfo *minfo, char *str)
{
	long long now;

	pthread_mutex_lock(&minfo->print);
	now = get_time();
	if (minfo->dead != -1 || minfo->end == 1)
	{
		pthread_mutex_unlock(&minfo->print);
		return ;
	}
	printf("%lld %d %s", now - minfo->start, parr->idx + 1, str);
	pthread_mutex_unlock(&minfo->print);
}
