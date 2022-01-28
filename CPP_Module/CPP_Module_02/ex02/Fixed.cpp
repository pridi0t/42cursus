/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:53 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/28 20:01:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor
Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int ivalue)
{
	this->value = roundf(ivalue * 256);		// 2^8 = 256
}

Fixed::Fixed(const float fvalue)
{
	this->value = roundf(fvalue * 256);		// 2^8 = 256
}

Fixed::Fixed(const Fixed& fix)
{
	(*this) = fix;
}

// assignation operator overload
Fixed	&Fixed::operator = (const Fixed &fix)
{
	setRawBits(fix.getRawBits());
	return (*this);
}

// Comparision operators
bool	Fixed::operator > (const Fixed &fix)
{
	return (getRawBits() > fix.getRawBits());
}

bool	Fixed::operator < (const Fixed &fix)
{
	return (getRawBits() < fix.getRawBits());
}

bool	Fixed::operator >= (const Fixed &fix)
{
	return (getRawBits() >= fix.getRawBits());
}

bool	Fixed::operator <= (const Fixed &fix)
{
	return (getRawBits() <= fix.getRawBits());
}

bool	Fixed::operator == (const Fixed &fix)
{
	return (getRawBits() == fix.getRawBits());
}

bool	Fixed::operator != (const Fixed &fix)
{
	return (getRawBits() != fix.getRawBits());
}

// Arithmetic operators
Fixed	Fixed::operator + (const Fixed &fix)
{
	Fixed result(*this);
	result.setRawBits(result.getRawBits() + fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator - (const Fixed &fix)
{
	Fixed result(*this);
	result.setRawBits(result.getRawBits() - fix.getRawBits());
	return (result);
}

Fixed	Fixed::operator * (const Fixed &fix)
{
	Fixed result(*this);
	result.setRawBits(result.getRawBits() * fix.getRawBits() / 256);	// 2^8 = 256
	return (result);
}

Fixed	Fixed::operator / (const Fixed &fix)
{
	Fixed result(*this);
	result.setRawBits(result.getRawBits() * 256 / fix.getRawBits());	// 2^8 = 256
	return (result);
}

// Increment/Decrement operators
Fixed&		Fixed::operator ++ ()
{
	++(this->value);
	return (*this);
}

const Fixed	Fixed::operator ++ (int)
{
	Fixed result(*this);
	++(*this);
	return (result);
}

Fixed&		Fixed::operator -- ()
{
	--(this->value);
	return (*this);
}

const Fixed	Fixed::operator -- (int)
{
	Fixed result((*this));
	--(*this);
	return (result);
}

// Destructor
Fixed::~Fixed()
{}

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
	return ((double)this->value / 256);
}

int		Fixed::toInt(void) const
{
	return (int)((double)this->value / 256);
}

Fixed&	Fixed::min(Fixed &a, Fixed &b)
{
	//if ((Fixed)a < (Fixed)b)
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::min(const Fixed &a, const Fixed &b)
{
	//if ((Fixed)a < (Fixed)b)
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed &a, Fixed &b)
{
	//if ((Fixed)a > (Fixed)b)
	if (a > b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed &a, const Fixed &b)
{
	//if ((Fixed)a > (Fixed)b)
	if (a > b)
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed &fix)
{
	return (os << fix.toFloat());
}
