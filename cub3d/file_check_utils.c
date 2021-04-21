/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 22:06:42 by hyojang           #+#    #+#             */
/*   Updated: 2021/04/21 22:09:00 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int simple_atoi(char *line, int *i)
{
	int result;

	result = 0;
	while (ft_isdigit(line[*i]) == 1)
	{
		result = (result * 10) + (line[*i] - '0');
		(*i)++;		
	}
	return (result);
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
}

int print_error(int errno, char *s)
{
	if (errno == 1)
		printf("Error\n%s Duplicate value\n", s);
	else if (errno == 2)
		printf("Error\n%s Separator error(or %s value may be negative)\n", s, s);
	else if (errno == 3)
		printf("Error\n%s Line never ends\n", s);
	else if (errno == 4)
		printf("Error\n%s RGB value must be between 0 and 255\n", s);
	else if (errno == 5)
		printf("Error\n%s file is not .xpm\n", s);
	else if (errno == 6)
		printf("Error\n%s file open failed\n", s);
	return errno;
}