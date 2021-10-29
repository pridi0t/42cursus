/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 04:51:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# define EAT 0
# define SLEEP 1
# define THINK 2
typedef struct s_stat{
	pthread_t	id;
	int			status;
}	t_stat;

typedef struct s_pstat{
	//int		eat;
	//int		sleep;
	//int		think;
	int		dead_cnt;
	int		status;
	int		eat_cnt;
}	t_pstat;

typedef struct s_minfo{
	int		philo;
	t_stat	*pinfo;
	int		*finfo;
	int		eat;
	int		sleep;
	int		think;
	int		die;
	int		must_eat;
	int		dflag;
}	t_minfo;

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	print_minfo(t_minfo *minfo);
#endif