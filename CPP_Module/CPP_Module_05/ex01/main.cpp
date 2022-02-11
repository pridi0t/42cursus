/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/12 03:24:17 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		// constructor
		Bureaucrat normal1;
		std::cout << normal1 << std::endl;

		Bureaucrat normal2("normal2", 2);
		normal2.upGrade();
		std::cout << normal2 << std::endl;

		Bureaucrat normal3(normal2);
		normal3.downGrade();
		std::cout << normal3 << std::endl;

		// assignation constructor
		Bureaucrat normal4("normal4", 150);
		normal1 = normal4;
		std::cout << normal1 << std::endl;
		std::cout << normal4 << std::endl;

		// exception test
		//Bureaucrat abnormal1("abnormal", -1);
		//Bureaucrat abnormal2("abnormal", 151);

		//normal2.upGrade();
		//normal4.downGrade();

	} catch (std::exception & e)
	{
		std::cout << "exception catch" << std::endl;
	}
	return 0;
}
