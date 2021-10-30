/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:54:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 07:40:44 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval time;

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
		write(2, "gettimeofday error\n", 19);
	/*
	if (errnum == 2)
		write(2, "status error\n", 18);
	*/
}

int	print_status(t_minfo *minfo, int philo_num, int stat)
{
	pthread_mutex_lock(&minfo->print_mutex);
	printf("%lld ", get_time() - minfo->start);
	if (stat == G_FORK)
		printf("%d has taken a fork\n", philo_num);
	else if (stat == EAT)
	{
		printf("%d is eating\n", philo_num);
		(minfo->pidinfo[philo_num].eat_cnt)++;
	}
	else if (stat == SLEEP)
		printf("%d is sleeping\n", philo_num);
	else if (stat == THINK)
		printf("%d is thinking\n", philo_num);
	else if (stat == DEAD)
	{
		printf("%d died\n", philo_num);
		minfo->dead++;
		minfo->pidinfo[philo_num].status = 0;
	}
	else
		return (-1);
	pthread_mutex_unlock(&minfo->print_mutex);
	return (0);
}

/*
void	free_data(t_minfo *minfo, t_pstat **pstat)
{
	int i;

	free(*minfo->pidinfo);
	*minfo->pidinfo = NULL;
	free(*minfo->finfo);
	*minfo->finfo = NULL;
	i = -1;
	while (++i < *minfo->philo)
		pthread_mutex_destroy(*minfo->mfork[i]);
	pthread_mutex_destroy(&minfo.flag_mutex);
	pthread_mutex_destroy(&minfo.print_mutex);
	*pstat = NULL;
}
*/
