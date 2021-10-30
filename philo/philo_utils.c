/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:54:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 02:07:20 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	print_err(t_minfo *minfo, int errnum)
{
	if (errnum == 1)
		write(2, "---> gettimeofday error\n", 24);
	if (errnum == 2)
		write(2, "---> status error\n", 18);
	minfo->err = errnum;
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
void	print_minfo(t_minfo *minfo)
{
	int i;

	printf("---------- info ----------\n");
	printf("philo\t:\t%d\n", minfo->philo);
	printf("finfo\t:\t%d\n", *(minfo->finfo));
	printf("must_eat:\t%d\n", minfo->must_eat);
	printf("dead\t:\t%d\n", minfo->dead);
	printf("start\t:\t%d\n", minfo->start);
	printf("err\t:\t%d\n", minfo->err);
	printf("[end\t:\t%d]\n", minfo->end);
	printf("--------------------------\n");
	printf("\n===== fork status =====\n");
	i = -1;
	while (++i < minfo->philo)
		printf("%d ", minfo->finfo[i]);
	printf("\n=======================\n");
}

void	print_pstat(t_pstat *pstat)
{
	printf("-----------\n");
	printf("minfo:%p\n", pstat->minfo);
	printf("philo_num:\t%d\n", pstat->philo_num);
	printf("eat\t:\t%d\n", pstat->eat);
	printf("sleep\t:\t%d\n", pstat->sleep);
	printf("think\t:\t%d\n", pstat->think);
	printf("dead_cnt:\t%d\n", pstat->dead_cnt);
	printf("status\t:\t%d\n", pstat->status);
	printf("start:\t%d\n", pstat->start);
	printf("-----------\n");
}
