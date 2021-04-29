/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/30 05:26:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stack.h"

void	print_map(t_info *info)
{
	int i;

	i = 0;
	while (i < info->rlen)
	{
		printf("%s\n", info->map[i]);
		i++;
	}
	printf("\n==================================\n");
}

int		main(void)
{
	t_gnl		gnl;
	t_info		info;
	t_stacktype s;
	t_loc		l;

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
	
	print_map(&info);
	convert_map(&gnl, &info);
	print_map(&info);
	
	return (0);
}
