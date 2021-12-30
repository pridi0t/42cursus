/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:08:51 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 22:03:49 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int Zombie::num = 0;

Zombie::Zombie() 
{
	this->name = "DEFAULT_ZOMBIE" + std::to_string(++num);
}

Zombie::~Zombie()
{
	std::cout << "<" << this->name << "> died X_X" << std::endl;
}

void	Zombie::Announce()
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
