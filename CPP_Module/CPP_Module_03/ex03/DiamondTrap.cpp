/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:11:11 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 22:57:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	std::cout << "[DiamondTrap] default constructor called" << std::endl;

	this->cname = ClapTrap::name;
	this->FragTrap::max_hp = 100;
	this->FragTrap::hitpoints = FragTrap::max_hp;
	this->ScavTrap::energy_points = 50;
	this->ScavTrap::attack_damage = 20;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "[DiamondTrap] <" << name << "> constructor called" << std::endl;
	
	this->cname = ClapTrap::name;
	this->FragTrap::max_hp = 100;
	this->FragTrap::hitpoints = FragTrap::max_hp;
	this->ScavTrap::energy_points = 50;
	this->ScavTrap::attack_damage = 20;
}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{
	std::cout << "[DiamondTrap] copy constructor called" << std::endl;
	(*this) = d;
}

// Assignation operator overload
DiamondTrap &DiamondTrap::operator = (const DiamondTrap &d)
{
	std::cout << "[DiamondTrap] assignation operator called" << std::endl;
	
	this->name = d.name;
	this->cname = d.cname;
	this->max_hp = d.max_hp;
	this->hitpoints = d.hitpoints;
	this->energy_points = d.energy_points;
	this->attack_damage = d.attack_damage;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] <" << name << "> destructor called" << std::endl;
}

// Override
void DiamondTrap::status()
{
	std::cout << "------------ status ------------" << std::endl;
	std::cout << std::setw(14) << std::left << "name" << ": " << this->name << std::endl;
	std::cout << std::setw(14) << "ClapTrap::Name" << ": " << this->cname << std::endl;
	std::cout << std::setw(14) << "hitpoints" << ": " << this->hitpoints << std::endl;
	std::cout << std::setw(14) << "energy points" << ": " << this->energy_points << std::endl;
	std::cout << std::setw(14) << "attack damage" << ": " << this->attack_damage << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] whoAmI called ===" << std::endl;
	std::cout << "name      : " << this->name << std::endl;
	std::cout << "clap name : " << this->cname << std::endl;
}
