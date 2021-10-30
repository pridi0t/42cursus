/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 00:47:36 by hyojang          ###   ########.fr       */
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
# define E_END 20
# define DEAD 0
# define EAT 1
# define SLEEP 2
# define THINK 3
typedef struct s_pidinfo{
	pthread_t	pid;
	int			eat_cnt;
} t_pidinfo;

typedef struct s_minfo{
	int				philo;
	t_pidinfo		*pidinfo;
	int				*finfo;
	pthread_mutex_t	*mfork;
	int				must_eat;
	int				dead;
	int				end;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	print_mutex;
	int				start;
	int				err;
} t_minfo;	

typedef struct s_pstat{
	t_minfo	*minfo;
	int		eat;
	int		sleep;
	int		think;
	int		philo_num;
	int		dead_cnt;
	int		status;
	int		start;
}	t_pstat;

int		ft_atoi(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		get_time(void);
void	print_err(t_minfo *minfo, int errnum);
void	free_data(t_minfo *minfo, t_pstat **pstat);
void	print_minfo(t_minfo *minfo);
void	print_pstat(t_pstat *pstat);
#endif