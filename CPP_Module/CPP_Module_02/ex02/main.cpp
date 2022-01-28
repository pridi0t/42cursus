// ////////////////////////////////////////////////////////////////////////// //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2022/01/20 18:13:33 by hyojang           #+#    #+#             //
/*   Updated: 2022/01/28 12:02:16 by hyojang          ###   ########.fr       */
//                                                                            //
// ////////////////////////////////////////////////////////////////////////// //

#include <iostream>
#include "Fixed.hpp"

int main(void) {

	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	//std::cout << Fixed::max(a, b) << std::endl;
	/*
	Fixed	a(10.2f);
	Fixed	b;

	b = Fixed(10.3f);
	std::cout << "=== before === " << std::endl;
	std::cout << "[raw  ] a : " << a.getRawBits() << ", b : " << b.getRawBits() << std::endl;
	std::cout << "[float] a : " << a.toFloat() << ", b : " << b.toFloat() << std::endl;
	
	std::cout << "=== result === " << std::endl;
	std::cout << a << " / " << b << " : " << "[raw] : " << (a / b).getRawBits() << ", [float] : " << (a / b).toFloat() << std::endl;
	std::cout << "[raw  ] a : " << a.getRawBits() << ", b : " << b.getRawBits() << std::endl;
	std::cout << "[float] a : " << a.toFloat() << ", b : " << b.toFloat() << std::endl;

	std::cout << b << " / " << a << " : " << "[raw] : " << (b / a).getRawBits() << ", [float] : " << (b / a).toFloat() << std::endl;
	std::cout << "[raw  ] a : " << a.getRawBits() << ", b : " << b.getRawBits() << std::endl;
	std::cout << "[float] a : " << a.toFloat() << ", b : " << b.toFloat() << std::endl;
	
	std::cout << a << " / " << a << " : " << "[raw] : " << (a / a).getRawBits() << ", [float] : " << (a / a).toFloat() << std::endl;
	std::cout << "[raw  ] a : " << a.getRawBits() << ", b : " << b.getRawBits() << std::endl;
	std::cout << "[float] a : " << a.toFloat() << ", b : " << b.toFloat() << std::endl;

	std::cout << "a / a / a / a : [raw] : " << (a / a / a / a).getRawBits() << ", [float] : " << (a / a / a / a).toFloat() << std::endl;
	std::cout << "[raw  ] a : " << a.getRawBits() << ", b : " << b.getRawBits() << std::endl;
	*/
	return 0;
}
