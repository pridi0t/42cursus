/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:53:22 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/16 10:53:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		main(void)
{
	int		fd;
	int		result;
	char	*line;
	char	map[MAP_SIZE][MAP_SIZE];

	ft_memset(&map, '0', sizeof(map));
	result = 1;
	fd = open("1.cub", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		printf("%s\n", line);
		convert_arr(map, line);
		free(line);
	}
	map_print(map);

	return 0;
}
