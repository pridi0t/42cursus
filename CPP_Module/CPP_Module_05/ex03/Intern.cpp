/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:38:00 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 14:55:03 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}

// Destructor
Intern::~Intern() {}

Form *Intern::makeForm(std::string fname, std::string target)
{
	std::string sarr[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form *farr[3] = {}
}

// Exception Class
const char* Intern::FormNotFoundException::what() const throw()
{
	return ("[Intern] form not found.... T.T");
}
