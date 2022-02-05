/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:32:29 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 23:00:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ScavTrap] default constructor called" << std::endl;
	this->max_hp = S_HP;
	this->hitpoints = max_hp;
	this->energy_points = S_EP;
	this->attack_damage = S_DMG;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] <" << name << "> constructor called" << std::endl;

	this->max_hp = S_HP;
	this->hitpoints = max_hp;
	this->energy_points = S_EP;
	this->attack_damage = S_DMG;
}

ScavTrap::ScavTrap(const ScavTrap &s)
{
	std::cout << "[ScavTrap] copy constructor called" << std::endl;
	(*this) = s;
}

// Assignation operator overload
ScavTrap &ScavTrap::operator = (const ScavTrap &s)
{
	std::cout << "[ScavTrap] assignation operator called" << std::endl;
	
	this->name = s.name;
	this->max_hp = s.max_hp;
	this->hitpoints = s.hitpoints;
	this->energy_points = s.energy_points;
	this->attack_damage = s.attack_damage;
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

void	ScavTrap::guardGate()
{
	std::cout << "[ScavTrap] <" << name << "> Gate keeper mode ON" << std::endl;
}

