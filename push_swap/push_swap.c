/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 20:01:05 by hyojang           #+#    #+#             */
/*   Updated: 2021/06/12 22:10:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_a(int argc, char *argv[], DLList **head)
{
	int i;

	i = argc - 1;
	while (i >= 0)
	{
		insert_first(head, ft_atoi(argv[i]));
		i--;
	}
}

int		check_int(char *str)
{
	int i;
	int strlen;
	long long num;

	strlen = ft_strlen(str);
	if (ft_strncmp(str, "-0", 2) == 0)
		return (1);
	i = -1;
	if (str[0] == '-')
		i++;
	while (++i < strlen)
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	if (i != strlen)
		return (1);
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

int		check_input(int argc, char *argv[])
{
	int i;
	int j;
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
	i = 1;
	while (i < (argc - 1) && (arr[i] < arr[i + 1]))
		i++;
	if (i == argc - 1)
		exit(1);
	free(arr);
	return (0);
}

int		main(int argc, char *argv[])
{
	DLList	*a;
	DLList	*b;
	char	**str;
	int		cnt;
	int		p1;
	int		p2;

	init(&a);
	init(&b);
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		cnt = 0;
		while (str[cnt] != 0)
			cnt++;
		if (cnt == 1)
		{
			if (check_int(str[0]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			return(0);
		}
	}
	else
	{
		cnt = argc - 1;
		str = &argv[1];
	}
	if (check_input(cnt, str))
		return (0);
	insert_a(cnt, str, &a);
	if (cnt == 3)
	{
		sort3_a(&a);
		return (0);
	}
	else if (cnt == 5)
	{
		sort5_a(&a, &b, 5);
		return (0);
	}
	find_pivot(a, &p1, &p2, cnt);
	a_to_b(&a, &b, cnt);
	return(0);
}