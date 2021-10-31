/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/31 12:50:41 by hyojang          ###   ########.fr       */
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

/*
# define D_END 10
# define E_END 20
# define DEAD 0
# define G_FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
*/
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
	long long		start;
	pthread_mutex_t	print;
	pthread_t		mt;
}	t_minfo;

int			parse_arg(int argc, char *argv[], t_minfo *minfo);
long long	get_time(void);
void		print_err(int errnum);
#endif