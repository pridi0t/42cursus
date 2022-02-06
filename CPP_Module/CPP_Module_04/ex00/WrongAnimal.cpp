/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:25:58 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 05:43:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructor
WrongAnimal::WrongAnimal()
{
	std::cout << "[WrongAnimal] default constructor called" << std::endl;
	
	this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &w)
{
	std::cout << "[WrongAnimal] copy constructor called" << std::endl;
	
	(*this) = w;
}

// Assignation operator overload
WrongAnimal& WrongAnimal::operator = (const WrongAnimal &w)
{
	this->type = w.type;
	return (*this);
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "[WrongAnimal] makeSound called" << std::endl;
}
