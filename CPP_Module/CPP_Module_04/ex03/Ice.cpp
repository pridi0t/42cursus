/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:28:08 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 10:28:18 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructor
Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice &i)
{
	(*this) = i;
}

// Assignation operator overload
Ice& Ice::operator = (const Ice &i)
{
	if (this != &i)
		this->type = i.type;
	return (*this);
}

// Destructor
Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
