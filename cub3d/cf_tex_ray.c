/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cf_tex_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 15:05:31 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 17:46:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cfinfo(t_info *info, t_cfinfo *cf, int y)
{
	(cf->raydir0).x = info->dir_x - info->plane_x;
	(cf->raydir0).y = info->dir_y - info->plane_y;
	(cf->raydir1).x = info->dir_x + info->plane_x;
	(cf->raydir1).y = info->dir_y + info->plane_y;
	cf->p = y - (info->r).height / 2;
	cf->posz = 0.5 * (info->r).height;
	cf->row_distance = cf->posz / cf->p;
	(cf->floorstep).x = cf->row_distance * ((cf->raydir1).x - \
			(cf->raydir0).x) / (info->r).width;
	(cf->floorstep).y = cf->row_distance * ((cf->raydir1).y - \
			(cf->raydir0).y) / (info->r).width;
	(cf->floor).x = info->pos_x + cf->row_distance * (cf->raydir0).x;
	(cf->floor).y = info->pos_y + cf->row_distance * (cf->raydir0).y;
	(cf->cell).x = (cf->floor).x;
	(cf->cell).y = (cf->floor).y;
	(cf->t).x = (int)((TEX_WIDTH) * ((cf->floor).x - \
				(cf->cell).x)) & (TEX_WIDTH - 1);
	(cf->t).y = (int)((TEX_HEIGHT) * ((cf->floor).y - \
				(cf->cell).y)) & (TEX_HEIGHT - 1);
	(cf->floor).x += (cf->floorstep).x;
	(cf->floor).y += (cf->floorstep).y;
	cf->floortexture = 2;
	cf->ceilingtexture = 2;
}

void	cf_ray(t_info *info)
{
	t_cfinfo	cfinfo;
	int			color;
	int			y;
	int			x;

	y = -1;
	while (++y < (info->r).height)
	{
		init_cfinfo(info, &cfinfo, y);
		x = -1;
		while (++x < (info->r).width)
		{
			color = info->texture[cfinfo.floortexture][TEX_WIDTH * \
					(cfinfo.t).y + (cfinfo.t).x];
			color = (color >> 1) & 8355711;
			(info->buf)[y][x] = color;
			color = info->texture[cfinfo.ceilingtexture][TEX_WIDTH * \
					(cfinfo.t).y + (cfinfo.t).x];
			color = (color >> 1) & 8355711;
			(info->buf)[(info->r).height - y - 1][x] = color;
		}
	}
}
