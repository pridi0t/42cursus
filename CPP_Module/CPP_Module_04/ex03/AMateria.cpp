/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:30:05 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 10:49:52 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructor
AMateria::AMateria()
{
	this->type = "";
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::AMateria(const AMateria &a)
{
	(*this) = a;
}

// Assignation operator overload
AMateria& AMateria::operator = (const AMateria &a)
{
	if (this != &a)
		this->type = a.type;
	return (*this);
}

// Destructor
AMateria::~AMateria() {}

std::string const & AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
