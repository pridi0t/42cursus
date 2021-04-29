/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:52:28 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/30 00:33:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
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
	int		rlen;
	int		clen;
	int		iflen;
	char	**map;
}			t_info;

typedef	struct {
	int		fd;
	int		result;
	char	*line;
}			t_gnl;



// file_check.c
void	input_info(t_info *info, char *line, int *flag);
// file_check_utils.c
int		simple_atoi(char *line, int *i);
void	ft_cstrncpy(char *dst, char *src, int n);
void	init_info(t_info *info);
void	info_err(int errno, char *tex_name, char *line);
// map_convert.c
void	call_gnl(t_gnl *gnl, t_info *info);
void	convert_map(t_gnl *gnl, t_info *info);
void	alc_arr(t_info *info);
#endif
