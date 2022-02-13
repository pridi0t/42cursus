/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:08:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 14:00:45 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotmyRequestForm.hpp"

RobotmyRequestForm::RobotmyRequestForm() {}

// Constructor
RobotmyRequestForm::RobotmyRequestForm(std::string target) : Form("RobotmyRequestForm", target, 72, 45) {}

RobotmyRequestForm::RobotmyRequestForm(const RobotmyRequestForm &r) : Form(r){}

// Assignation operator overload
RobotmyRequestForm& RobotmyRequestForm::operator = (const RobotmyRequestForm &r)
{
	Form::operator=(r);
	return (*this);
}

// Destructor
RobotmyRequestForm::~RobotmyRequestForm() {}

// Override
void	RobotmyRequestForm::execute(Bureaucrat const & excutor) const
{
	Form::checkForm(excutor);
	srand((unsigned int)time(NULL));
	if ((rand() % 100 + 1) <= 50)
	{
		std::cout << "o(^O^)----->>>>   o<-<  wing~~~~~~" << std::endl;
		std::cout << "<" << excutor.getName() << "> has been robotomized successfully 50% of the time" << std::endl;
	}
	else
		std::cout << "<" << excutor.getName() << "> Robotization failed T.T" << std::endl;
}
