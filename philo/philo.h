/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 10:14:39 by hyojang          ###   ########.fr       */
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
# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
typedef struct s_stat{
	pthread_t	id;
	int			status;
}	t_stat;

typedef struct s_minfo{
	int				philo;
	t_stat			*pinfo;
	int				*finfo;
	pthread_mutex_t	*mfork;
	int				eat;
	int				sleep;
	int				think;
	int				die;
	int				must_eat;
	int				dflag;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	print_mutex;
	int				start;
}	t_minfo;

typedef struct s_pstat{
	t_minfo	*minfo;
	int		philo_num;
	int		dead_cnt;
	int		status;
	int		eat_cnt;
}	t_pstat;

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		cvt_time(struct timeval input);
void	print_minfo(t_minfo *minfo);
#endif