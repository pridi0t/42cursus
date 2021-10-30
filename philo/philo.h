/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 07:40:42 by hyojang          ###   ########.fr       */
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
# define G_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
typedef struct s_pidinfo{
	pthread_t	pid;
	int			eat_cnt;
	int			status;
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
	long long		start;
	int				err;
} t_minfo;	

typedef struct s_pstat{
	t_minfo		*minfo;
	int			eat;
	int			sleep;
	int			think;
	int			philo_num;
	int			dead_cnt;
	//int		status;
	long long	start;
}	t_pstat;

int			check_input(int argc, char *argv[]);
// ft_fuc
int			ft_atoi(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
// init
int			init_minfo(char *argv[], t_minfo *minfo);
t_pstat		*init_pstat(int argc, char *argv[], t_minfo *minfo, t_pstat *pstat);
// utils
long long	get_time(void);
void		ms_sleep(int ms);
void		print_err(int errnum);
int			print_status(t_minfo *minfo, int philo_num, int stat);
//
void		free_data(t_minfo *minfo, t_pstat **pstat);
#endif