/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 19:58:23 by hyojang          ###   ########.fr       */
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

typedef struct s_minfo	t_minfo;
typedef struct s_pinfo {
	pthread_t		pt;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t	*r_hand;
	long long		last_eat;
	int				idx;
	int				eat_cnt;
	t_minfo			*minfo;
}	t_pinfo;

typedef struct s_minfo {
	t_pinfo			*parr;
	pthread_mutex_t	*mfork;
	int				philo;
	int				dead_cnt;
	int				eat;
	int				sleep;
	int				must_eat;
	int				dead;
	int				end;
	int				err;
	long long		start;
	pthread_mutex_t	print;
	pthread_t		mt;
}	t_minfo;

int			init_all(int argc, char *argv[], t_minfo *minfo);
void		free_all(t_minfo *minfo);
int			parse_arg(int argc, char *argv[], t_minfo *minfo);
long long	get_time(void);
void		ms_sleep(int ms);
void		print_err(int errnum);
void		print_status(t_pinfo *parr, t_minfo *minfo, char *str);
void		*monitor(void *arg);
void		start_cycle(t_minfo *minfo);
int			ft_atoi(const char *str);
#endif