/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:10:35 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 01:14:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructor
Animal::Animal()
{
	std::cout << "[Animal] default constructor called" << std::endl;
	
	this->type = "";
}

Animal::Animal(const Animal &a)
{
	std::cout << "[Animal] copy constructor called" << std::endl;
	
	(*this) = a;
}

// Assignation operator overload
Animal& Animal::operator = (const Animal &a)
{
	this->type = a.getType();
	return (*this);
}

// Destructor
Animal::~Animal()
{
	std::cout << "[Animal] destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}

void		Animal::makeSound() const
{
	std::cout << "[Animal] makeSound called" << std::endl;
}
