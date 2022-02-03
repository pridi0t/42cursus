/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:30:24 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 14:19:35 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : max(10)
{
	std::cout << "<" << name << "> constructor called" << std::endl;

	this->name = name;
	this->hitpoints = max;
	this->energy_point = max;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "<" << this->name << "> destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "<" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints > amount)
		hitpoints -= amount;
	else
		hitpoints = 0;

	std::cout << "<" << name << "> takes <" << amount << "> damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitpoints += amount;
	if (hitpoints >= max)
		hitpoints = max;
	energy_point += amount;
	if (energy_point >= max)
		energy_point = max;
	
	std::cout << "<" << name << "> repair completed (" << amount << ")" << std::endl;
}

void	ClapTrap::status()
{
	std::cout << "------------ status ------------" << std::endl;
	std::cout << std::setw(14) << std::left << "name" << ": " << this->name << std::endl;
	std::cout << std::setw(14) << "hitpoints" << ": " << this->hitpoints << std::endl;
	std::cout << std::setw(14) << "energy point" << ": " << this->energy_point << std::endl;
	std::cout << std::setw(14) << "attack damage" << ": " << this->attack_damage << std::endl;
	std::cout << "--------------------------------" << std::endl;
}
