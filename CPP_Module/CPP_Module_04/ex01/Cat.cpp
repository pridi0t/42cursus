/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:43:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:47:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructor
Cat::Cat() : Animal()
{
	std::cout << "[cat] default constructor called" << std::endl;

	this->type = "Cat";
	this->cb = new Brain();
}

Cat::Cat(const Cat &c) : Animal()
{
	std::cout << "[Cat] copy constructor called" << std::endl;

	this->cb = new Brain();
	(*this) = c;
}

// Assignation operator overload
Cat& Cat::operator = (const Cat &c)
{
	if (this != &c)
	{
		this->type = c.getType();
		delete (this->cb);
		this->cb = new Brain(c.getBr());
	}
	return (*this);
}

// Destructor
Cat::~Cat()
{
	std::cout << "[Cat] destructor called" << std::endl;
	
	delete this->cb;
}

// Override
void Cat::makeSound() const
{
	std::cout << "[Cat] o(=´∇｀=)o meaw~~~~~~~~~~" << std::endl;
}

Brain Cat::getBr() const
{
	return Brain(*(this->cb));
}

void Cat::setBr(int index, std::string value)
{
	this->cb->setBr(index, value);
}

void Cat::printBrain()
{
	for (int i = 0 ; i < this->cb->getSizeBr() ; i++)
	{
		std::cout << this->cb->getBr(i) << " ";
		if (i % 10 == 9)
			std::cout << std::endl;
	}
}
