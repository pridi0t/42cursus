/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_ray_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:16:02 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 15:18:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int y;
	int x;

	img->img = mlx_xpm_file_to_image(info->mlx, \
			path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, \
			&img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	load_image(info, info->texture[0], info->no, &info->img);
	load_image(info, info->texture[1], info->so, &info->img);
	load_image(info, info->texture[2], info->we, &info->img);
	load_image(info, info->texture[3], info->ea, &info->img);
	load_image(info, info->texture[4], info->s, &info->img);
}
