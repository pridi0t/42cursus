/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:32:29 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 19:50:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ScavTrap] default constructor called" << std::endl;
	this->mode = 0;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] <" << name << "> constructor called" << std::endl;

	this->mode = 0;
	this->hitpoints = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	std::cout << "[ScavTrap] copy constructor called" << std::endl;
	(*this) = s;
}

// Assignation operator overload
ScavTrap &ScavTrap::operator = (const ScavTrap &s)
{
	this->name = s.name;
	this->hitpoints = s.hitpoints;
	this->energy_points = s.energy_points;
	this->attack_damage = s.attack_damage;
	this->mode = s.mode;
	return (*this);
}

// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] <" << name << "> destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const & target)
{
	std::cout << "[ScavTrap] <" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	hitpoints += amount;
	if (hitpoints >= 100)
		hitpoints = 100;
	energy_points += amount;
	if (energy_points >= 50)
		energy_points = 50;
	
	std::cout << "[ScavTrap] <" << name << "> has been repaird by <" << amount << ">" << std::endl;
}

void ScavTrap::status()
{
	std::cout << "------------ status ------------" << std::endl;
	std::cout << std::setw(18) << std::left << "name" << ": " << this->name << std::endl;
	std::cout << std::setw(18) << "hitpoints" << ": " << this->hitpoints << std::endl;
	std::cout << std::setw(18) << "energy points" << ": " << this->energy_points << std::endl;
	std::cout << std::setw(18) << "attack damage" << ": " << this->attack_damage << std::endl;
	std::cout << std::setw(18) << "[GATE KEEPER mode]" << ": ";
	if (mode == 1)
		std::cout << "ON" << std::endl;
	else
		std::cout << "OFF" << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] <" << name << "> guardGate called" << std::endl;

	if (mode == 0)
	{
		mode = 1;
		std::cout << "Gate keeper mode ON" << std::endl;
	}
	else
		std::cout << "Gate keeper mode is already running" << std::endl;
}

