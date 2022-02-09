/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:25:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 14:06:14 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructor
Dog::Dog() : Animal()
{
	std::cout << "[Dog] defulat constructor called" << std::endl;

	this->type = "Dog";
	this->db = new Brain();
}

Dog::Dog(const Dog &d) : Animal()
{
	std::cout << "[Dog] copy constructor called" << std::endl;

	this->db = new Brain();
	(*this) = d;
}

// Assignation operator overload
Dog& Dog::operator = (const Dog &d)
{
	if (this != &d)
	{
		this->type = d.getType();
		if (this->db != NULL)
		{
			delete (this->db);
			this->db = NULL;
		}
		this->db = new Brain(d.getBr());
	}
	return (*this);
}

// Destructor
Dog::~Dog()
{
	std::cout << "[Dog] destructor called" << std::endl;
	
	delete this->db;
}

// Override
void Dog::makeSound() const
{
	std::cout << "[Dog] (U・x・U) woof - woof!!" << std::endl;
}

Brain Dog::getBr() const
{
	return Brain(*(this->db));
}

void Dog::setBr(int index, std::string value)
{
	this->db->setBr(index, value);
}

void Dog::printBrain()
{
	for (int i = 0 ; i < this->db->getSizeBr() ; i++)
	{
		std::cout << this->db->getBr(i) << " ";
		if (i % 10 == 9)
			std::cout << std::endl;
	}
}
