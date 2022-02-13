/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:08:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 16:52:57 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form(r){}

// Assignation operator overload
RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &r)
{
	Form::operator=(r);
	return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Override
void	RobotomyRequestForm::execute(Bureaucrat const & excutor) const
{
	Form::checkForm(excutor);
	srand((unsigned int)time(NULL));
	if ((rand() % 100 + 1) <= 50)
	{
		std::cout << "o(^O^)----->>>>   o<-<  wing~~~~~~" << std::endl;
		std::cout << "<" << this->getTarget() << "> has been robotomized successfully 50% of the time" << std::endl;
	}
	else
		std::cout << "<" << this->getTarget() << "> Robotization failed T.T" << std::endl;
}
