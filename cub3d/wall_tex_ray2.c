/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tex_ray2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:05:41 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/12 03:27:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		select_tex(t_winfo *w)
{
	if (w->side == 0 && (w->raydir).x < 0)
		return (0);
	else if (w->side == 0 && (w->raydir).x > 0)
		return (1);
	else if (w->side == 1 && (w->raydir).y < 0)
		return (2);
	else if (w->side == 1 && (w->raydir).y > 0)
		return (3);
	return (-1);
}

void	convert_color(t_info *info)
{
	info->fcolor = info->f.r * 65536;
	info->fcolor += info->f.g * 256;
	info->fcolor += info->f.b;
	info->ccolor = info->c.r * 65536;
	info->ccolor += info->c.g * 256;
	info->ccolor += info->c.b;
}

void	draw(t_info *info, int x, t_winfo *w)
{
	int		y;
	int		color;

	convert_color(info);
	y = -1;
	while (++y < (info->r).height)
	{
		if (y < w->draw_start)
			info->buf[y][x] = info->ccolor;
		else if (y < w->draw_end)
		{
			(w->tex).y = (int)w->texpos & (TEX_HEIGHT - 1);
			w->texpos += w->dstep;
			color = info->texture[w->texnum][TEX_HEIGHT * \
					(w->tex).y + (w->tex).x];
			if (w->side == 1)
				color = (color >> 1) & 8355711;
			info->buf[y][x] = color;
		}
		else
			info->buf[y][x] = info->fcolor;
	}
	info->zbuf[x] = w->perp_wall_dist;
}
