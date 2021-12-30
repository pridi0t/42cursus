/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:30:52 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/31 00:57:39 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon->getType();
}

void	setType(Weapon weapon)
{
	this->weapon = weapon;
}

void	attack()
{
	std::cout << this->name << "attacks with his " << this->weapon << std::endl;
}
