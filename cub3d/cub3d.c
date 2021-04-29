/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/30 00:35:32 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_gnl		gnl;
	t_info		info;

	init_info(&info);
	ft_memset(&gnl, 0, sizeof(gnl));
	call_gnl(&gnl, &info);
	/*
	printf("R : %d %d\n", info.r.width, info.r.height);
	printf("NO : %s\n", info.no);
	printf("SO : %s\n", info.so);
	printf("WE : %s\n", info.we);
	printf("EA : %s\n", info.ea);
	printf("S : %s\n", info.s);
	printf("F : %d %d %d\n", info.f.r, info.f.g, info.f.b);
	printf("C : %d %d %d\n", info.c.r, info.c.g, info.c.b);
	printf("rlen : %d\n", info.rlen);
	printf("clen : %d\n", info.clen);
	*/
	alc_arr(&info);
	convert_map(&gnl, &info);
	return (0);
}