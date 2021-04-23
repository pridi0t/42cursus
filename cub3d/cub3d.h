/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:52:28 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/23 10:48:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "stack.h"
# include "libft.h"

typedef struct {
	int		width;
	int		height;
}			t_r;

typedef struct {
	int		r;
	int		g;
	int		b;
}			t_rgb;

typedef struct {
	t_r		r;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_rgb	f;
	t_rgb	c;
}			t_info;

typedef struct {
	int		linenum;
	int		maxlen;
	element	src;
} 			t_mapinfo;

void	init_info(t_info *info);
void	input_info(t_info *info, char *line, t_mapinfo *minfo);
int		simple_atoi(char *line, int *i);
void	info_err(int errno, char *tex_name, char *line);
#endif
