/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:59:10 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 08:08:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form(p.getName(), p.getTarget(), p.getRequiredGrade(), p.getExeGrade()) {}

// Assignation operator overload
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &p)
{
	*(const_cast<std::string *>(&this->name)) = p.name;
	*(const_cast<std::string *>(&this->target)) = p.target;
	this->signature = p.signature;
	*(const_cast<int *>(&this->required_grade)) = p.required_grade;
	*(const_cast<int *>(&this->exe_grade)) = p.exe_grade;
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Override
void	PresidentialPardonForm::execute(Bureaucrat const & excutor) const
{
	try {
		checkForm(excutor);
		std::cout << "<" << excutor.getName() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}
