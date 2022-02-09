/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:41:00 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 09:22:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructor
MateriaSource::MateriaSource()
{
	this->meta_size = 0;
	for (int i = 0 ; i < 4 ; i++)
		this->meta[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &m)
{
	(*this) = m;
}

// Assignation operator overload
MateriaSource& MateriaSource::operator = (const MateriaSource &m)
{
	this->meta_size = m.meta_size;
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->meta[i] != NULL)
		{
			delete this->meta[i];
			this->meta[i] = NULL;
			this->meta[i] = m.meta[i]->clone();
		}
	}
	return (*this);
}

// Destructor
MateriaSource::~MateriaSource()
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->meta[i] != NULL)
		{
			delete this->meta[i];
			this->meta[i] = NULL;
		}
	}
}

// Override
void MateriaSource::learnMateria(AMateria* m)
{
	if (this->meta_size == 4)
		return ;
	this->meta[this->meta_size++] = m->clone();
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	AMateria *result = NULL;

	for (int i = 0 ; i < this->meta_size ; i++)
	{
		if (this->meta[i]->getType() == type)
			result = meta[i]->clone();
	}
	return (result);
}
