/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:16:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/10/30 00:54:48 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
typedef struct s_stat{
	int		id;
	int		status;
}	t_stat;

typedef struct s_pstat{
	//int		eat;
	//int		sleep;
	//int		think;
	int		dead_cnt;
	int		status;
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
#endif