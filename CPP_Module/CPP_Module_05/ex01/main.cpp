/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/12 20:51:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try 
	{
		// constructor
		Form f1;
		std::cout << f1 << std::endl;
		Form f2("f2", 10, 10);
		std::cout << f2 << std::endl;
		Form f3(f2);
		std::cout << f3 << std::endl;

		// Assignation operator overload
		Form f4("f4", 1, 1);
		f1 = f4;
		std::cout << f1 << std::endl;
		
		// getter test
		std::cout << "name : " << f4.getName() << std::endl;
		std::cout << "signature : " << f4.getSignature() << std::endl;
		std::cout << "required grade: " << f4.getRequiredGrade() << std::endl;
		std::cout << "exe grade : " << f4.getExeGrade() << std::endl;

		// function test
		std::cout << std::endl;
		Bureaucrat b1("b1", 1);
		Bureaucrat b2("b2", 150);

		f2.beSigned(b1);
		std::cout << f2;
		f2.beSigned(b2);
		
		// constructor exception
		//Form f5("f5", 0, 150);
		//Form f6("f6", 1, 151);
		//Form f7("f7", -1, -1);

	} catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return 0;
}
