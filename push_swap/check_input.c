/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:11:27 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/15 12:13:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		except_int(char *str, int *i, int *strlen)
{
	*strlen = ft_strlen(str);
	if (ft_strncmp(str, "-0", 2) == 0)
		return (1);
	*i = -1;
	if (str[0] == '-')
		(*i)++;
	while (++(*i) < *strlen)
	{
		if (!ft_isdigit(str[*i]))
			return (1);
	}
	if (*i != *strlen)
		return (1);
	return (0);
}

int		check_int(char *str)
{
	int			i;
	int			strlen;
	long long	num;

	if (except_int(str, &i, &strlen) == 1)
		exit(1);
	num = 0;
	i = -1;
	if (str[0] == '-')
		i++;
	while (++i < strlen)
		num = (num * 10) + (str[i] - '0');
	if (str[0] == '-')
		num *= -1;
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

void	except_input(int argc, int *arr)
{
	int i;
	int j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			if (arr[i] == arr[j])
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
	}
	i = 0;
	while ((i < argc - 1) && (arr[i] < arr[i + 1]))
		i++;
	if (i == argc - 1)
		exit(1);
}

int		check_input(int argc, char *argv[])
{
	int i;
	int *arr;

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	i = -1;
	while (++i < argc)
	{
		if (check_int(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		arr[i] = ft_atoi(argv[i]);
	}
	except_input(argc, arr);
	free(arr);
	return (0);
}
