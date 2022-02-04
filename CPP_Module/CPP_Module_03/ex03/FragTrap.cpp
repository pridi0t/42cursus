/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:13:02 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 04:42:33 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[FragTrap] default constructor called" << std::endl;

	this->max_hp = 100;
	this->hitpoints = max_hp;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "[FragTrap] <" << name << "> constructor called" << std::endl;
	
	this->max_hp = 100;
	this->hitpoints = max_hp;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &f)
{
	std::cout << "[FragTrap] copy constructor called" << std::endl;
	(*this) = f;
}

// Assignation operator overload
FragTrap &FragTrap::operator = (const FragTrap &f)
{
	std::cout << "[FragTrap] assignation operator called" << std::endl;
	
	this->name = f.name;
	this->max_hp = f.max_hp;
	this->hitpoints = f.hitpoints;
	this->energy_points = f.energy_points;
	this->attack_damage = f.attack_damage;
	return (*this);
}

// Destructor
FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] <" << name << "> destructor called" << std::endl;
}

void	FragTrap::attack(std::string const & target)
{
	std::cout << "[FragTrap] <" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] <" << name << "> highFivesGuys called" << std::endl;
	std::cout << "Shall we high-five? :)" << std::endl;
}
