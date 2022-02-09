/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 06:03:06 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 10:26:42 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructor
Character::Character()
{
	this->name = "";
	this->inven_size = 0;
	for (int i = 0 ; i < 4 ; i++)
		this->inven[i] = NULL;
}

Character::Character(std::string name)
{
	this->name = name;
	this->inven_size = 0;
	for (int i = 0 ; i < 4 ; i++)
		this->inven[i] = NULL;
}

Character::Character(const Character &c)
{
	(*this) = c;
}

// Assignation operator overload
Character& Character::operator = (const Character &c)
{
	if (this != &c)
	{
		this->name = c.name;
		this->inven_size = c.inven_size;
		for (int i = 0 ; i < 4 ; i++)
		{
			if (this->inven[i] != NULL)
			{
				delete this->inven[i];
				this->inven[i] = NULL;
			}
			if (c.inven[i] != NULL)
				this->inven[i] = c.inven[i]->clone();
		}
	}
	return (*this);
}

// Destructor
Character::~Character()
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if (this->inven[i] != NULL)
			delete this->inven[i];
	}
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{	
	if (this->inven_size >= 4 || m == NULL)
		return ;
	this->inven[this->inven_size++] = m->clone();
}

void Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
		return ;
	if (this->inven[idx] == NULL)
		return ;
	this->inven[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) 
{
	if (idx >= 4 || idx < 0)
		return ;
	if (this->inven[idx] == NULL)
		return ;
	this->inven[idx]->use(target);
}
