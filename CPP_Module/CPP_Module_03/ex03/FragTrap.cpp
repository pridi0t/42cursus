/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:13:02 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/06 02:34:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[FragTrap] default constructor called" << std::endl;

	this->max_hp = F_HP;
	this->hitpoints = max_hp;
	this->energy_points = F_EP;
	this->attack_damage = F_DMG;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->max_hp = F_HP;
	this->hitpoints = max_hp;
	this->energy_points = F_EP;
	this->attack_damage = F_DMG;
	
	std::cout << "[FragTrap] <" << this->name << "> constructor called" << std::endl;
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

// Override
void	FragTrap::attack(std::string const & target)
{
	std::cout << "[FragTrap] <" << name << "> attacks " << "<" << target << ">, causing <" << attack_damage << "> points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] <" << name << "> highFivesGuys called" << std::endl;
	std::cout << "Shall we high-five? :)" << std::endl;
}
