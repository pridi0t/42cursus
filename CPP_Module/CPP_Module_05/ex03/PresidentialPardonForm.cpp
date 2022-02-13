/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:59:10 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 16:49:46 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form(p) {}

// Assignation operator overload
PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &p)
{
	Form::operator=(p);
	return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Static member function
Form	*PresidentialPardonForm::create(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

// Override
void	PresidentialPardonForm::execute(Bureaucrat const & excutor) const
{
	Form::checkForm(excutor);
	std::cout << "<" << this->getTarget() << "> has been pardoned by Zafod Beeblebrox" << std::endl;
}
