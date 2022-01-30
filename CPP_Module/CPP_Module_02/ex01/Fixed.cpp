/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:53 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/30 12:32:15 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int ivalue)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (ivalue * (1 << this->fbit));
}

Fixed::Fixed(const float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(fvalue * (1 << this->fbit));
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	(*this) = fix;
}

// assignation operator overload
Fixed  &Fixed::operator = (const Fixed &fix)
{
	std::cout << "Assignation operator called" << std::endl;
	setRawBits(fix.getRawBits());
	return (*this);
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((double)this->value / (1 << this->fbit));
}

int		Fixed::toInt(void) const
{
	return (int)((double)this->value / (1 << this->fbit));
}

std::ostream& operator << (std::ostream& os, const Fixed &fix)
{
	return (os << fix.toFloat());
}
