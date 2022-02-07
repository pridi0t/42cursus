/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:47:39 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:47:04 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructor
Brain::Brain()
{
	std::cout << "[Brain] default constructor called" << std::endl;
	
	std::string tmp = "0123456789";

	this->size_br = 100;
	for (int i = 0 ; i < this->size_br; i++)
		this->br[i] = tmp.at((i + 1) % 10);
}

Brain::Brain(const Brain &b)
{
	std::cout << "[Brain] copy constructor called" << std::endl;
	
	(*this) = b;
}

// Assignation operator overload
Brain& Brain::operator = (const Brain &b)
{
	if (this != &b)
	{
		this->size_br = b.size_br;
		for (int i = 0 ; i < this->size_br ; i++)
			this->br[i] = b.getBr(i);
	}
	return (*this);
}

// Destructor
Brain::~Brain()
{
	std::cout << "[Brain] destructor called" << std::endl;
}

std::string Brain::getBr(int index) const
{
	if (index > this->size_br)
	{
		std::cout << "index must be smaller than brain size" << std::endl;
		return ("");
	}
	return (this->br[index]);
}

void Brain::setBr(int index, std::string value)
{
	if (index > this->size_br)
	{
		std::cout << "index must be smaller than brain size" << std::endl;
		return ;
	}
	this->br[index] = value;
}

int	Brain::getSizeBr() const
{
	return (this->size_br);
}
