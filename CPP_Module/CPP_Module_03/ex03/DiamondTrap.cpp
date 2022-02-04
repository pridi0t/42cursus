/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:11:11 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 05:22:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor
DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap] default constructor called" << std::endl;
	
	this->name = "";
	this->FragTrap::max_hp = 100;
	this->FragTrap::hitpoints = FragTrap::max_hp;
	this->ScavTrap::energy_points = 50;
	this->ScavTrap::attack_damage = 20;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "[DiamondTrap] constructor called" << std::endl;
	
	this->name = name;
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
	this->FragTrap::max_hp = d.max_hp;
	this->FragTrap::hitpoints = d.FragTrap::hitpoints;
	this->ScavTrap::energy_points = d.ScavTrap::energy_points;
	this->ScavTrap::attack_damage = d.ScavTrap::attack_damage;
	return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] <" << name << "> destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	std::cout << "[DiamondTrap] <" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "[DiamondTrap] whoAmI called ===" << std::endl;
	std::cout << "name      : " << this->name << std::endl;
	std::cout << "clap name : " << this->ClapTrap::name << std::endl;
}
