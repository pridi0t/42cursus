/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:55:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 15:15:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_rinfo(t_info *info)
{
	int i;

	info->pos_x = (double)(info->sloc).r + 0.5;
	info->pos_y = (double)(info->sloc).c + 0.5;
	info->dir_x = -1;
	info->dir_y = 0;
	info->plane_x = 0;
	info->plane_y = 0.66;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, (info->r).width, \
			(info->r).height, "mlx");
	info->buf = ft_calloc((info->r).height, sizeof(int *));
	info->texture = ft_calloc(5, sizeof(int *));
	info->move_speed = 0.4;
	info->rot_speed = 0.3;
	i = -1;
	while (++i < (info->r).height)
		info->buf[i] = ft_calloc((info->r).width, sizeof(int));
	i = -1;
	while (++i < 5)
		info->texture[i] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
}

int		main_loop(t_info *info)
{
	int x;
	int y;

	cf_ray(info);
	wall_ray(info);
	sprite_ray(info);
	y = -1;
	while (++y < (info->r).height)
	{
		x = -1;
		while (++x < (info->r).width)
			info->img.data[y * (info->r).width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, (info->img).img, 0, 0);
	return (0);
}

void	raycasting(t_info *info)
{
	init_rinfo(info);
	// malloc 확인하는 함수부분 있는데 지웠음
	load_texture(info);
	(info->img).img = mlx_new_image(info->mlx, \
			(info->r).width, (info->r).height);
	(info->img).data = (int *)mlx_get_data_addr((info->img).img, \
			&(info->img).bpp, &(info->img).size_l, &(info->img).endian);
	mlx_loop_hook(info->mlx, &main_loop, info);
	mlx_hook(info->win, X_EVENT_KEY_PRESS, 0, &key_press, info);
	mlx_loop(info->mlx);
}
