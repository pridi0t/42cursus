/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 04:02:49 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 11:03:56 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor
Form::Form() : name(""), required_grade(150), exe_grade(150)
{
	this->signature = false;
}

Form::Form(std::string name, int rgrade, int egrade) : name(name), required_grade(rgrade), exe_grade(egrade)
{
	if (rgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	if (rgrade > 150 || egrade > 150)
		throw GradeTooLowException();
	this->signature = false;
}

Form::Form(const Form &f) : name(f.name), required_grade(f.required_grade), exe_grade(f.exe_grade)
{
	if (f.required_grade < 1 || f.exe_grade < 1)
		throw GradeTooHighException();
	if (f.required_grade > 150 || f.exe_grade > 150)
		throw GradeTooLowException();
	this->signature = f.signature;
}

// Assignation operator overload
Form& Form::operator = (const Form &f)
{
	if (this != &f)
	{
		*(const_cast<std::string *>(&this->name)) = f.name;
		this->signature = f.signature;
		*(const_cast<int *>(&this->required_grade)) = f.required_grade;
		*(const_cast<int *>(&this->exe_grade)) = f.exe_grade;
	}
	return (*this);
}

// Destructor
Form::~Form() {}

std::string Form::getName() const
{
	return (this->name);
}

int	Form::getSignature() const
{
	return (this->signature);
}

int	Form::getRequiredGrade() const
{
	return (this->required_grade);
}

int	Form::getExeGrade() const
{
	return (this->exe_grade);
}

void	Form::beSigned(Bureaucrat &b)
{
	if (this->required_grade >= b.getGrade())
		this->signature = true;
	else
		throw GradeTooLowException();
}

// Exception Class
const char* Form::GradeTooHighException::what() const throw()
{
	return ("[Form Exception] Grade too high..T.T");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Form Exception] Grade too low..T.T");
}

// ostream overload
std::ostream& operator << (std::ostream& os, const Form &f)
{
	os << "===== Form status =====" << std::endl;
	os << std::setw(15) << std::left << "name" << ": " << f.getName() << std::endl;
	os << std::setw(15) << std::left << "signature" << ": ";
	if (f.getSignature() == true)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	os << std::setw(15) << std::left << "required grade" << ": " << f.getRequiredGrade() << std::endl;
	os << std::setw(15) << std::left << "exe grade" << ": " << f.getExeGrade() << std::endl;
	os << "=======================" << std::endl;
	return (os);
}
