/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 18:50:35 by hyojang          ###   ########.fr       */
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
# define D_END 10
# define M_END 20
# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
typedef struct s_minfo{
	int				philo;
	pthread_t		*pidinfo;
	int				*finfo;
	pthread_mutex_t	*mfork;
	int				must_eat;
	int				end;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	print_mutex;
	int				mtstart;
	int				err;
}	

typedef struct s_pstat{
	t_minfo	*minfo;
	int		eat;
	int		sleep;
	int		think;
	int		philo_num;
	int		dead_cnt;
	int		status;
	int		mstart;
	int		pstart;
	int		eat_cnt;
}	t_pstat;

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		cvt_time(struct timeval input);
void	print_minfo(t_minfo *minfo);
#endif