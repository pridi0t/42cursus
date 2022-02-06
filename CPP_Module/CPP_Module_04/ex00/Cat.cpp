/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:43:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 01:17:27 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal()
{
	std::cout << "[cat] defulat constructor called" << std::endl;

	this->type = "Cat";
}

Cat::Cat(const Cat &c)
{
	std::cout << "[Cat] copy constructor called" << std::endl;

	(*this) = c;
}

// Assignation operator overload
Cat& Cat::operator = (const Cat &c)
{
	this->type = c.type;
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] o(=´∇｀=)o meaw~~~~~~~~~~" << std::endl;
}
