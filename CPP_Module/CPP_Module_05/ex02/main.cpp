/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 15:55:21 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b150", 150);

	std::cout << "1) ShrubberyCreationForm =================" << std::endl;
	std::cout << "1-1) constructor test" << std::endl;
	ShrubberyCreationForm s1("s1");
	ShrubberyCreationForm s2(s1);
	ShrubberyCreationForm s3("s3");
	s2 = s3;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	
	std::cout << "1-2) function test" << std::endl;
	b1.signForm(s1);
	std::cout << s1 << std::endl;
	b1.executeForm(s1);
	
	b2.signForm(s2);
	std::cout << s2 << std::endl;
	b2.executeForm(s2);
	
	std::cout << "2) RobotmyRequestForm ====================" << std::endl;
	std::cout << "2-1) constructor test" << std::endl;
	RobotomyRequestForm r1("r1");
	RobotomyRequestForm r2(r1);
	RobotomyRequestForm r3("r3");
	r2 = r3;
	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
	std::cout << r3 << std::endl;
	
	std::cout << "2-2) function test" << std::endl;
	b1.signForm(r1);
	std::cout << r1 << std::endl;
	b1.executeForm(r1);
	
	b2.signForm(r2);
	std::cout << r2 << std::endl;
	b2.executeForm(r2);

	std::cout << "3) PresidentialPardonForm ===============" << std::endl;
	std::cout << "3-1) constructor" << std::endl;
	//PresidentialPardonForm a;
	PresidentialPardonForm p1("p1");
	PresidentialPardonForm p2(p1);
	PresidentialPardonForm p3("p3");
	p2 = p3;
	std::cout << p1 << std::endl;
	std::cout << p2 << std::endl;
	std::cout << p3 << std::endl;

	std::cout << "3-2) function test" << std::endl;
	b1.signForm(p1);
	std::cout << p1 << std::endl;
	b1.executeForm(p1);

	b2.signForm(p2);
	std::cout << p2 << std::endl;
	b2.executeForm(p2);

	return 0;
}
