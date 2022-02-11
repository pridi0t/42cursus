/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:37:47 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/11 23:19:34 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat() : name("")
{
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name)
{
	if (b.grade < 1)
		throw GradeTooHighException();
	if (b.grade > 150)
		throw GradeTooLowException();
	this->grade = b.grade;
}

// Assignation operator overload
Bureaucrat& Bureaucrat::operator = (const Bureaucrat &b)
{
	if (this != &b) {
		std::string *tmp = const_cast<std::string *>(&this->name);
		*tmp = b.name;
		this->grade = b.grade;
	}
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int			Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::upGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::downGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

// Exception Class Function
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Bureaucrat Exception] Grade too high..T.T");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Bureaucrat Exception] Grade too low..T.T");
}

std::ostream& operator << (std::ostream& os, const Bureaucrat &b)
{
	os << "========== status ==========" << std::endl;
	os << "name  : " << b.getName() << std::endl;
	os << "grade : " << b.getGrade() << std::endl;
	os << "============================" << std::endl;
	return (os);
}
