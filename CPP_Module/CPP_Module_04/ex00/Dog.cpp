/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:25:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 01:17:15 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal()
{
	std::cout << "[Dog] defulat constructor called" << std::endl;

	this->type = "Dog";
}

Dog::Dog(const Dog &d)
{
	std::cout << "[Dog] copy constructor called" << std::endl;

	(*this) = d;
}

// Assignation operator overload
Dog& Dog::operator = (const Dog &d)
{
	this->type = d.type;
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] (U・x・U) woof - woof!!" << std::endl;
}
