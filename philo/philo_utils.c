/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 03:54:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 08:40:27 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_minfo(t_minfo *minfo)
{
	int i;

	printf("---------- info ----------\n");
	printf("philo :\t\t%d\n", minfo->philo);
	printf("eat time :\t%d\n", minfo->eat);
	printf("sleep time :\t%d\n", minfo->sleep);
	printf("think time :\t%d\n", minfo->think);
	printf("dead_cnt :\t%d\n", minfo->die);
	printf("must_eat:\t%d\n", minfo->must_eat);
	printf("[dflag :\t%d]\n", minfo->dflag);
	printf("--------------------------\n");
	printf("\n===== pinfo(philo status) =====\n");
	i = -1;
	while (++i < minfo->philo)
	{
		printf("[%d]status : ", i);
		if (minfo->pinfo[i].status == EAT)
			printf("EAT\n");
		else if (minfo->pinfo[i].status == SLEEP)
			printf("SLEEP\n");
		else if (minfo->pinfo[i].status == THINK)
			printf("SHINK\n");
		else
			printf("error\n");
	}
	printf("===============================\n");
	printf("\n===== fork status =====\n");
	i = -1;
	while (++i < minfo->philo)
		printf("%d ", minfo->finfo[i]);
	printf("\n=======================\n");
}
