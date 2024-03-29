/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:04:43 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/12 10:21:04 by jitlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include "get_next_line.h"
# include "stack.h"
# include "libft.h"
# define TEX_HEIGHT 1024
# define TEX_WIDTH 1024
# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124
# define X_EVENT_KEY_PRESS 2
# define DESTROY_NOTIFY 17

typedef struct
{
	int			width;
	int			height;
}				t_r;

typedef struct
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct
{
	int			r;
	int			c;
	int			cnt;
	char		respawn;
}				t_sloc;

typedef struct
{
	double		x;
	double		y;
	int			texture;
}				t_sprite;

typedef struct
{
	int			size_l;
	int			*data;
	int			bpp;
	int			endian;
	int			img_width;
	int			img_height;
	void		*img;
}				t_img;

typedef struct
{
	t_r			r;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	t_rgb		f;
	t_rgb		c;
	int			fcolor;
	int			ccolor;
	int			rlen;
	int			clen;
	int			iflen;
	char		**map;
	t_sloc		sloc;
	int			scnt;
	double		*zbuf;
	int			*sp_order;
	double		*sp_dist;
	t_sprite	*sp;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	void		*mlx;
	void		*win;
	t_img		img;
	int			**buf;
	int			**texture;
	double		move_speed;
	double		rot_speed;
	int			m_width;
	int			m_height;
	int			save;
}	t_info;

typedef struct
{
	int			x;
	int			y;
}				t_ipair;

typedef struct
{
	double		x;
	double		y;
}				t_dpair;

typedef struct
{
	double		camerax;
	t_dpair		raydir;
	t_ipair		map;
	t_dpair		sidedist;
	t_dpair		deltadist;
	double		perp_wall_dist;
	t_ipair		step;
	double		dstep;
	int			hit;
	int			side;
	int			lineheight;
	int			draw_start;
	int			draw_end;
	int			texnum;
	double		wallx;
	t_ipair		tex;
	double		texpos;
}				t_winfo;

typedef struct
{
	t_dpair		sprite;
	int			sprite_height;
	int			sprite_width;
	double		invdet;
	t_dpair		transform;
	int			sprite_screenx;
	t_ipair		draw_start;
	t_ipair		draw_end;
	t_ipair		tex;
}	t_sinfo;

typedef	struct
{
	int			fd;
	char		*line;
}				t_gnl;

void			input_info(t_info *info, char *line, int *flag);
void			input_sprite_num(t_info *info);
int				simple_atoi(char *line, int *i);
void			ft_cstrncpy(char *dst, char *src, int n);
void			init_info(t_info *info);
void			tex_check(t_info *info);
void			info_err(int errno, char *tex_name, char *line);
void			file_err(int errno);
void			arr_free(t_info *info, int errno);
void			push_loc(t_stacktype *s, t_info *info, int r, int c);
void			call_gnl(t_gnl *gnl, t_info *info, char *file_name);
void			convert_map(t_gnl *gnl, t_info *info, char *file_name);
void			alc_2arr(t_info *info);
void			check_map(t_info *info);
void			check_loc(t_info *info, t_loc *l);
int				mdfs(t_stacktype *s, t_info *info, t_loc *l);
void			raycasting(t_info *info);
void			wall_ray(t_info *info);
void			draw(t_info *info, int x, t_winfo *w);
int				select_tex(t_winfo *w);
void			sprite_ray(t_info *info);
void			load_image(t_info *info, int *texture, char *path, t_img *img);
void			load_texture(t_info *info);
int				key_press(int key, t_info *info);
int				x_button(void);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void			save_bmp(t_info *info);
#endif
