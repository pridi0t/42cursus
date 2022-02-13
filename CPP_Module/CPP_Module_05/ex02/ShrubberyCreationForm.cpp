/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:06:08 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 18:02:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form(s) {}
		
// Assignation operator overload
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &s)
{
	Form::operator=(s);
	return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::FileWriteException::what() const throw()
{
	return ("[ShrubberyCreationForm] file write exception");
}

// Override
void	ShrubberyCreationForm::execute(Bureaucrat const & excutor) const
{
	std::ofstream ofs;
	std::string tmp = "                                               |\n\
                                              -x-\n\
                                               |\n\
              v .   ._, |_  .,\n\
           `-._\\/  .  \\ /    |/_\n\
               \\\\  _\\, y | \\//\n\
         _\\_.___\\\\, \\\\/ -.\\||\n\
           `7-,--.`._||  / / ,\n\
           /'     `-. `./ / |/_.'\n\
                     |    |//\n\
                     |_    /\n\
                     |-   |\n\
                     |   =|\n\
                     |    |\n\
--------------------/ ,  . \\--------._\n\
\n\
------------------------------------------------\n";
	Form::checkForm(excutor);
	ofs.open(this->getTarget() + "_shrubbery");
	if (!ofs.is_open())
		throw FileWriteException();
	ofs << tmp;
	ofs.close();
}
