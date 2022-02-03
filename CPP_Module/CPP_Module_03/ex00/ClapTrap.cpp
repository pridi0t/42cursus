/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:30:24 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 11:23:53 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "<" << name << "> constructor called" << std::endl;

	this->name = name;
	this->hitpoints = 10;
	this->energy_point = 10;
	this->attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "<" << this->name << "> destructor called" << std::endl;
}
/*
void ClapTrap::attack(std::string const & target)
{}

void ClapTrap::takeDamage(unsigned int amount)
{}

void ClapTrap::beRepaired(unsigned int amount)
{}
*/
void	ClapTrap::status()
{
	std::cout << "============ status ============" << std::endl;
	std::cout << std::setw(14) << std::left << "name" << ": " << this->name << std::endl;
	std::cout << std::setw(14) << "hitpoints" << ": " << this->hitpoints << std::endl;
	std::cout << std::setw(14) << "energy point" << ": " << this->energy_point << std::endl;
	std::cout << std::setw(14) << "attack damage" << ": " << this->attack_damage << std::endl;
	std::cout << "================================" << std::endl;
}
