/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:08:51 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/29 11:19:41 by hyojang          ###   ########.fr       */
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
	std::cout << "<" << this->name << "> died (X_X)" << std::endl;
}

void	Zombie::announce()
{
	std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
