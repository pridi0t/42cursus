/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:30:24 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 19:51:21 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructor
ClapTrap::ClapTrap()
{
	std::cout << "default constructor called" << std::endl;
	
	this->name = "";
	this->hitpoints = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "<" << name << "> constructor called" << std::endl;

	this->name = name;
	this->hitpoints = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	std::cout << "copy constructor called" << std::endl;
	(*this) = c;
}

// Assignation operator overload
ClapTrap &ClapTrap::operator = (const ClapTrap &c)
{
	std::cout << "assignation operator called" << std::endl;

	this->name = c.name;
	this->hitpoints = c.hitpoints;
	this->energy_points = c.energy_points;
	this->attack_damage = c.attack_damage;
	return (*this);
}

// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "<" << name << "> destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << "<" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints > amount)
		hitpoints -= amount;
	else
		hitpoints = 0;

	std::cout << "<" << name << "> takes <" << amount << "> damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	hitpoints += amount;
	if (hitpoints >= 10)
		hitpoints = 10;
	energy_points += amount;
	if (energy_points >= 10)
		energy_points = 10;
	
	std::cout << "<" << name << "> has been repaird by <" << amount << ">" << std::endl;
}

void	ClapTrap::status()
{
	std::cout << "------------ status ------------" << std::endl;
	std::cout << std::setw(14) << std::left << "name" << ": " << this->name << std::endl;
	std::cout << std::setw(14) << "hitpoints" << ": " << this->hitpoints << std::endl;
	std::cout << std::setw(14) << "energy points" << ": " << this->energy_points << std::endl;
	std::cout << std::setw(14) << "attack damage" << ": " << this->attack_damage << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
