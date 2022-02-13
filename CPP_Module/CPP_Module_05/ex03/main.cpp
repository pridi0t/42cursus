/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 16:29:22 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);

	Intern	someRandomIntern;
	Form*	rrf;

	std::cout << "1) shrubbery creation ===================" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "house");
	std::cout << *rrf << std::endl;
	b1.signForm(*rrf);
	std::cout << *rrf << std::endl;
	b1.executeForm(*rrf);
	b2.signForm(*rrf);
	delete rrf;
	
	std::cout << "2) robotomy request =====================" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "bender");
	std::cout << *rrf << std::endl;
	b1.signForm(*rrf);
	std::cout << *rrf << std::endl;
	b1.executeForm(*rrf);
	b2.signForm(*rrf);
	delete rrf;

	std::cout << "3) presidential pardon ==================" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "bender");
	std::cout << *rrf << std::endl;
	b1.signForm(*rrf);
	std::cout << *rrf << std::endl;
	b1.executeForm(*rrf);
	b2.signForm(*rrf);
	delete rrf;
	
	return 0;
}
