/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:02:15 by hyojang           #+#    #+#             */
/*   Updated: 2021/05/12 05:20:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		simple_atoi(char *line, int *i)
{
	int result;
	int tmp;
	int sign;

	result = 0;
	sign = 1;
	tmp = *i;
	if (line[*i] == '-')
	{
		sign *= -1;
		(*i)++;
	}
	while (ft_isdigit(line[*i]) == 1)
	{
		result = (result * 10) + (line[*i] - '0');
		(*i)++;
	}
	if (tmp == *i || (line[tmp] == '-' && result == 0))
		return (-1);
	return (result * sign);
}

void	ft_cstrncpy(char *dst, char *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

void	init_info(t_info *info)
{
	(info->r).width = -1;
	(info->r).height = -1;
	info->no = 0;
	info->so = 0;
	info->we = 0;
	info->ea = 0;
	info->s = 0;
	(info->f).r = -1;
	(info->f).g = -1;
	(info->f).b = -1;
	(info->c).r = -1;
	(info->c).g = -1;
	(info->c).b = -1;
	info->rlen = 0;
	info->clen = 0;
	info->iflen = 0;
	info->map = 0;
	(info->sloc).r = -1;
	(info->sloc).c = -1;
	(info->sloc).cnt = 0;
	(info->sloc).respawn = 0;
	info->scnt = 0;
}

void	info_err(int errno, char *name, char *line)
{
	if (errno == 1)
		perror("Error\nDuplicate value");
	else if (errno == 2)
		perror("Error\nSeparator error(or value < 0)");
	else if (errno == 3)
		perror("Error\nLine never ends.. parsing error");
	else if (errno == 5)
		perror("Error\nfile is not .xpm\n");
	else if (errno == 6)
		perror("Error\nfile open failed\n");
	else if (errno == 7)
		perror("Error\nempty or invalid value\n");
	printf("%s", name);
	if (line != 0)
		free(line);
	exit(1);
}
