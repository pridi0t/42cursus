/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:28:51 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 05:36:42 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructor
WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "[WrongCat] defulat constructor called" << std::endl;

	this->type = "Cat";
}

WrongCat::WrongCat(const WrongCat &w)
{
	std::cout << "[WrongCat] copy constructor called" << std::endl;

	(*this) = w;
}

// Assignation operator overload
WrongCat& WrongCat::operator = (const WrongCat &w)
{
	this->type = w.type;
	return (*this);
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] o(=´∇｀=)o meaw~~~~~~~~~~" << std::endl;
}
