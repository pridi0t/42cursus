/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:50:55 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/31 00:54:36 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon(std::string type)
{
	this->type = type;
}

const std::string&	getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}
