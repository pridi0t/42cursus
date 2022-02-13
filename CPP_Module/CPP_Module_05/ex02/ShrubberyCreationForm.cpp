/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:06:08 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 10:08:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string name)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s)
{}
		
// Assignation operator overload
ShrubberyCreation& ShrubberyCreation::operator = (const ShrubberyCreationForm &s)
{}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Override
void	ShrubberyCreationForm::execute(Bureaucrat const & excutor) const
{}
