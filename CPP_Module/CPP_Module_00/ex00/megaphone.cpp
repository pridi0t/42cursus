/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:39:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/11 20:09:34 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char *argv[])
{
	int i = 0;
	int j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (argv[++i] != 0)
	{
		j = -1;
		while (argv[i][++j] != 0)
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return 0;
}
