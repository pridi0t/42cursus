/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:01:11 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 01:29:24 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cycle(void *arg)
{
	//t_pstat stat;

	//ft_memcpy(stat, arg, sizeof(stat));
}

void	init_minfo(int argc, char *argv[], t_minfo *minfo)
{
	minfo->philo = ft_atoi(argv[1]);
	//minfo->nfork = philo;
	minfo->pinfo = (t_stat *)malloc(sizeof(t_pstat) * minfo->philo);
	minfo->finfo = (int *)malloc(sizeof(int) * minfo->philo);
	memset(minfo->pinfo, 0, sizeof(int) * minfo->philo);
	memset(minfo->finfo, 0, sizeof(int) * minfo->philo);	// not 0?

	minfo->eat = ft_atoi(argv[3]);
	minfo->sleep = ft_atoi(argv[4]);
	minfo->die = ft_atoi(argv[2]);
	minfo->think = minfo->die - minfo->eat - minfo->sleep;
	if (minfo->think < 0)
		minfo->think = 0;
	minfo->must_eat = 0;
	if (argc == 6)
		minfo->must_eat = ft_atoi(argv[5]);
	minfo->dflag = 0;
}

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
		printf("id : %d,\tstatus : %d\n", minfo->pinfo[i].id, minfo->pinfo[i].status);
	printf("===============================\n");
	printf("\n===== fork status =====\n");
	i = -1;
	while (++i < minfo->philo)
		printf("%d ", minfo->finfo[i]);
	printf("\n=======================\n");
}

int	main(int argc, char *argv[])
{
	t_minfo minfo;

	// have to add input exception
	init_minfo(argc, argv, &minfo);
	print_minfo(&minfo);
	
	return (0);
}
