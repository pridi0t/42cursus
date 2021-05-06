/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:52:28 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/07 08:00:39 by hyojang          ###   ########.fr       */
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
#define tex_height 1024
#define tex_width 1024
#define K_A 0
#define K_S 1
#define K_D 2
#define K_W 13
#define K_ESC 53
#define X_EVENT_KEY_PRESS 2

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
	int		r;
	int		c;
	int		cnt;
	char	respawn;
}			t_sloc;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;

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
	t_sloc	sloc;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		**buf;
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
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
// map_utils.c
void	file_err(int errno);
void	arr_free(t_info *info, int errno);
void	push_loc(t_stacktype *s, t_info *info, int r, int c);
// map_convert.c
void	call_gnl(t_gnl *gnl, t_info *info);
void	convert_map(t_gnl *gnl, t_info *info);
void	alc_2arr(t_info *info);
// map_check.c
void	check_map(t_info *info);
void	check_loc(t_info *info, t_loc *l);
int		mdfs(t_stacktype *s, t_info *info, t_loc *l);
#endif
