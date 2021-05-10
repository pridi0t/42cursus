/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:44:36 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/11 04:52:24 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	keyset_ws(int key, t_info *info)
{
	if (key == K_W)
	{
		if ((info->map[(int)(info->pos_x + info->dir_x * \
						info->move_speed)][(int)info->pos_y] - '0') == 0)
			info->pos_x += info->dir_x * info->move_speed;
		if ((info->map[(int)info->pos_x][(int)(info->pos_y + \
						info->dir_y * info->move_speed)] - '0') == 0)
			info->pos_y += info->dir_y * info->move_speed;
	}
	if (key == K_S)
	{
		if ((info->map[(int)(info->pos_x - info->dir_x * \
						info->move_speed)][(int)info->pos_y] - '0') == 0)
			info->pos_x -= info->dir_x * info->move_speed;
		if ((info->map[(int)info->pos_x][(int)(info->pos_y - \
						info->dir_y * info->move_speed)] - '0') == 0)
			info->pos_y -= info->dir_y * info->move_speed;
	}
}

void	keyset_ad(int key, t_info *info)
{
	if (key == K_A)
	{
		if ((info->map[(int)(info->pos_x - info->dir_y\
				* 2 * info->move_speed)][(int)(info->pos_y)] - '0') == 0)
			info->pos_x -= info->dir_y * info->move_speed;
		if ((info->map[(int)(info->pos_x)][(int)(info->pos_y \
				+ info->dir_x * info->move_speed)] - '0') == 0)
			info->pos_y += info->dir_x * info->move_speed;
	}
	if (key == K_D)
	{
		if ((info->map[(int)(info->pos_x + info->dir_y \
				* 2 * info->move_speed)][(int)(info->pos_y)] - '0') == 0)
			info->pos_x += info->dir_y * info->move_speed;
		if ((info->map[(int)(info->pos_x)][(int)(info->pos_y \
				- info->dir_x * info->move_speed)] - '0') == 0)
			info->pos_y -= info->dir_x * info->move_speed;
	}
}

void	keyset_lr(int key, t_info *info, double old_dirx, double old_planex)
{
	if (key == K_RIGHT)
	{
		info->dir_x = info->dir_x * cos(-info->rot_speed) - \
					info->dir_y * sin(-info->rot_speed);
		info->dir_y = old_dirx * sin(-info->rot_speed) + \
					info->dir_y * cos(-info->rot_speed);
		info->plane_x = info->plane_x * cos(-info->rot_speed) - \
						info->plane_y * sin(-info->rot_speed);
		info->plane_y = old_planex * sin(-info->rot_speed) + \
						info->plane_y * cos(-info->rot_speed);
	}
	if (key == K_LEFT)
	{
		info->dir_x = info->dir_x * cos(info->rot_speed) - \
					info->dir_y * sin(info->rot_speed);
		info->dir_y = old_dirx * sin(info->rot_speed) + \
					info->dir_y * cos(info->rot_speed);
		info->plane_x = info->plane_x * cos(info->rot_speed) - \
						info->plane_y * sin(info->rot_speed);
		info->plane_y = old_planex * sin(info->rot_speed) + \
						info->plane_y * cos(info->rot_speed);
	}
}

int		key_press(int key, t_info *info)
{
	keyset_ws(key, info);
	keyset_lr(key, info, info->dir_x, info->plane_x);
	keyset_ad(key, info);
	if (key == K_ESC)
		exit(0);
	return (0);
}

int		x_button(void)
{
	exit(0);
}
