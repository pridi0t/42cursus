/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/29 13:49:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char *argv[])
{
	Karen		karen;
	std::string	level;

	if (argc != 2)
	{
		std::cout << "Must have 2 arguments." << std::endl;
		return (1);
	}
	level = argv[1];
	karen.complain(level);
	
	return (0);
}
