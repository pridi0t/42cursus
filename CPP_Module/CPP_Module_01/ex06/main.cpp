/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/13 17:21:38 by hyojang          ###   ########.fr       */
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
	/*
	std::cout << "==" << std::endl;
	karen.complain("");
	std::cout << "==" << std::endl;
	karen.complain("error");
	std::cout << "==" << std::endl;
	karen.complain("warning");
	std::cout << "==" << std::endl;
	karen.complain("info");
	std::cout << "==" << std::endl;
	karen.complain("debug");
	*/
	return (0);
}
