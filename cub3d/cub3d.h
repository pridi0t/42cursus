/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:04:43 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 17:36:48 by hyojang          ###   ########.fr       */
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
# define X_EVENT_KEY_PRESS 2

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
	int			rlen;
	int			clen;
	int			iflen;
	char		**map;
	// sprite
	t_sloc		sloc;
	int			scnt;
	double		*zbuf;
	int			*sp_order;
	double		*sp_dist;
	t_sprite	*sp;
	// ray casting
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
	t_dpair		raydir0;
	t_dpair		raydir1;
	int			p;
	double		posz;
	double		row_distance;
	t_dpair		floorstep;
	t_dpair		floor;
	t_ipair		cell;
	t_ipair		t;
	int			floortexture;
	int			ceilingtexture;
}	t_cfinfo;

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
	int			result;
	char		*line;
}				t_gnl;

// file_check1.c
void			input_info(t_info *info, char *line, int *flag);
// file_check2.c
void			input_sprite_num(t_info *info);
// file_check_utils.c
int				simple_atoi(char *line, int *i);
void			ft_cstrncpy(char *dst, char *src, int n);
void			init_info(t_info *info);
void			info_err(int errno, char *tex_name, char *line);
// map_utils.c
void			file_err(int errno);
void			arr_free(t_info *info, int errno);
void			push_loc(t_stacktype *s, t_info *info, int r, int c);
// map_convert.c
void			call_gnl(t_gnl *gnl, t_info *info);
void			convert_map(t_gnl *gnl, t_info *info);
void			alc_2arr(t_info *info);
// map_check.c
void			check_map(t_info *info);
void			check_loc(t_info *info, t_loc *l);
int				mdfs(t_stacktype *s, t_info *info, t_loc *l);
// ray.c
void			raycasting(t_info *info);
// cf_tex_ray.c
void			cf_ray(t_info *info);
// wall_tex_ray.c
void			wall_ray(t_info *info);
// sprite_tex_ray.c
void			sprite_ray(t_info *info);
// tex_ray_utils.c
void			load_image(t_info *info, int *texture, char *path, t_img *img);
void			load_texture(t_info *info);
// key.c
int				key_press(int key, t_info *info);
#endif
