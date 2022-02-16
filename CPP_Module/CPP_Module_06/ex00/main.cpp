/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:50:11 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 16:22:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Scalar.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "[Error] The argument must be 1 except for the program name." << std::endl;
		return (1);
	}
	
	try {
		Scalar s(argv[1]);
		std::cout << s;
	} catch (std::exception & e) {
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
	}
	
	return 0;
}
