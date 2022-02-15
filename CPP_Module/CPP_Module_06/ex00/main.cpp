/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:50:11 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 00:31:10 by marvin           ###   ########seoul.kr  */
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
	
	return 0;
}
