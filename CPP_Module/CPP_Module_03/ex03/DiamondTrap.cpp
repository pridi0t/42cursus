/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:11:11 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 04:16:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
	this->name = "";
	this->FragTrap::max_hp = 100 
	this->FragTrap::hitpoints = FragTrap::max_hp;
	this->ScavTrap::energy_points = 50;
	this->ScavTrap::attack_damage = 20;
}

DiamondTrap::DiamondTrap(std::string name)
{}

DiamondTrap::DiamondTrap(const DiamondTrap &d)
{}
