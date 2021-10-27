/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 20:26:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/07/04 23:20:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	num_print(int n, int fd)
{
	char	*num;

	num = "0123456789";
	if (n >= 10)
		num_print(n / 10, fd);
	write(fd, num + (n % 10), 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		num_print((n * -1), fd);
	}
	else
		num_print(n, fd);
}
