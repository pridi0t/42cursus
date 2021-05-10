/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:01:38 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/10 14:14:25 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(void)
{
	t_gnl		gnl;
	t_info		info;
	t_stacktype s;
	t_loc		l;

	ft_memset(&info, 0, sizeof(info));
	init_info(&info);
	init_stack(&s);
	ft_memset(&gnl, 0, sizeof(gnl));
	call_gnl(&gnl, &info);
	alc_2arr(&info);
	convert_map(&gnl, &info);
	check_loc(&info, &l);
	check_map(&info);
	if (mdfs(&s, &info, &l) != 0)
		arr_free(&info, 4);
	convert_map(&gnl, &info);
	info.map[info.sloc.r][info.sloc.c] = '0';
	input_sprite_num(&info);
	raycasting(&info);
	return (0);
}
