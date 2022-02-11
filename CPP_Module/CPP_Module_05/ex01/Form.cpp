/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 04:02:49 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/12 04:13:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor
Form::Form(){}
Form::Form(const Form &f) {}

// Assignation operator overload
Form& Form::operator = (const Form &f) {}

// Destructor
Form::~Form() {}

std::string Form::getName() const {}
int			Form::getSignature() const {}
void		Form::getRequiredGrade() const {}
void		Form::getExeGrade() const {}
void		Form::beSigned() {}
void		Form::signForm() {}

// Exception Class
class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
};

class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw();
};

// ostream overload
std::ostream& operator << (std::ostream& os, const Form &f);
