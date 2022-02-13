/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 12:02:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotmyRequestForm.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b150", 150);

	std::cout << "2) RobotmyRequestForm ====================" << std::endl;
	std::cout << "2-1) constructor test" << std::endl;
	RobotmyRequestForm r1("r1");
	RobotmyRequestForm r2(r1);
	RobotmyRequestForm r3("r3");
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
