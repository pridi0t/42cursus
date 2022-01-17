/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:53 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/17 19:14:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed()
{
	intever_parts = 0;
	fractional_parts = 0;
}

Fixed(const Fixed& fix)
{

}

Fixed  &Fixed::operator = (const Fixed &fix)
{}

~Fixed()
{}

int		getRawBits(void)
{}

void	setRawbits(int const raw)
{}

int 
