/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:37:47 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/10 15:23:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat()
{
	this->name = "";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeToHighException();
	if (grade > 150)
		throw Bureaucrat::GradeToLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	(*this) = b;
}

// Assignation operator overload
Bureaucrat& Bureaucrat::operator = (const Bureaucrat &b)
{
	if (this != &b) {
		this->name = b.name;
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
		throw Bureaucrat::GradeToHighException();
	this->grade--;
}

void		Bureaucrat::downGrade()
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeToLowException();
	this->grade++;
}

// Exception Class Function
const char* Bureaucrat::GradeTooHighException::what() const
{
	return ("[Bureaucrat Exception] Grade too high..");
}

const char* Bureaucrat::GradeTooLowException::what() const
{
	return ("[Bureaucrat Exception] Grade too low..");
}

std::ostream& operator << (std::ostream& os, const Bureaucrat &b)
{
	os << "========== status ==========" << std::endl;
	os << "name  : " << this->name << std::endl;
	os << "grade : " << this->grade << std::endl;
	return (os);
}
