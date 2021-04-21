/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/21 22:11:23 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
void	convert_arr(char map[][MAP_SIZE], char *line)
{
	static int	i = 0;
	int			j;

	j = 0;
	while (line[j] != 0 && j < MAP_SIZE)
	{
		if (line[j] == ' ')
			map[i][j] = '0';
		else
			map[i][j] = line[j];
		j++;
	}
	i++;
}

void	map_print(char map[][MAP_SIZE])
{
	int i, j;

	for (i = 0; i < MAP_SIZE; i++)
	{
		for (j = 0 ; j < MAP_SIZE ; j++)
			printf("%c", map[i][j]);
		printf("\n");
	}
}
*/

int	main(void)
{
	int		fd;
	int		result;
	char	*line;
	t_info 	info;

	//ft_memset(&map, '0', sizeof(map));
	init_info(&info);
	result = 1;
	fd = open("1.cub", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		if (line != 0)
			if (input_info(&info, line) != 0)
			{
				free(line);
				break;
			}
		//printf("%s\n", line);
		//convert_arr(map, line);
		free(line);
	}
	//map_print(map);

	printf("R : %d %d\n", info.r.width, info.r.height);
	printf("NO : %s\n", info.no);
	printf("SO : %s\n", info.so);
	printf("WE : %s\n", info.we);
	printf("EA : %s\n", info.ea);
	printf("S : %s\n", info.s);
	printf("F : %d %d %d\n", info.f.r, info.f.g, info.f.b);
	printf("C : %d %d %d\n", info.c.r, info.c.g, info.c.b);

	return (0);
}