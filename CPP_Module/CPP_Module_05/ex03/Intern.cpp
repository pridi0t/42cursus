/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:38:00 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 16:20:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

// Constructor
Intern::Intern() {}
Intern::Intern(const Intern &i)
{
	(void)i;
}

// Assignation operator overload
Intern& Intern::operator = (const Intern &i)
{
	(void)i;
	return (*this);
}

// Destructor
Intern::~Intern() {}

Form *Intern::makeForm(std::string fname, std::string target)
{
	std::string sarr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *(*farr[3])(std::string&) = { &ShrubberyCreationForm::create, &RobotomyRequestForm::create, &PresidentialPardonForm::create};
	
	try {
		int i = 0;
		while (sarr[i] != fname && i < 3)
			i++;
		if (i == 3)
			throw FormNotFoundException();
		std::cout << "Intern creates <" << sarr[i] << ">" << std::endl;
		return ((*farr[i])(target));
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (NULL);
	}
}

// Exception Class
const char* Intern::FormNotFoundException::what() const throw()
{
	return ("[Intern] form not found.... T.T");
}
