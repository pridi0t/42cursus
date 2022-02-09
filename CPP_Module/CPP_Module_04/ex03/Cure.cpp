/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 09:00:03 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 10:28:18 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructor
Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure &c)
{
	(*this) = c;
}

// Assignation operator overload
Cure& Cure::operator = (const Cure &c)
{
	if (this != &c)
		this->type = c.type;
	return (*this);
}

// Destructor
Cure::~Cure() {}

// Override
AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
