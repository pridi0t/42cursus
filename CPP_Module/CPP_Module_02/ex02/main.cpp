/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:13:33 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/28 08:25:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {

	/*
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	*/

	Fixed	a(10.2f);
	Fixed	b;

	b = Fixed(10.3f);
	std::cout << "=== result === " << std::endl;
	std::cout << a << " < " << b << " : " << (a < b) << std::endl;
	std::cout << b << " < " << a << " : " << (b < a) << std::endl;
	std::cout << a << " < " << a << " : " << (a < a) << std::endl;

	return 0;
}
