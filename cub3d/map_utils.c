/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 03:14:04 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/30 05:08:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	file_err(int errno)
{
	if (errno == 1)
		perror("Error\nFile open error");
	else if (errno == 2)
		perror("Error\nFile close error");
	else if (errno == 3)
		perror("Error\nMalloc error");
	else if (errno == 4)
		perror("Error\nInvalid map");
	else if (errno == 5)
		perror("Error\nRespawn error");
	exit(1);
}

void	arr_free(t_info *info, int errno)
{
	int i;

	i = 0;
	while (i < info->rlen)
	{
		if (info->map[i] != 0)
			free(info->map[i]);
		i++;
	}
	free(info->map);
	info->map = 0;
	file_err(errno);
}

void	push_loc(t_stacktype *s, t_info *info, int r, int c)
{
	t_loc tmp;

	if (r < 0 || c < 0)
		return ;
	if (info->map[r][c] == '0' || info->map[r][c] == '2')
	{
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
