/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:24:31 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 04:46:16 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "span.hpp"

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// basic test
	std::cout << "====== copy constructor ====" << std::endl;
	Span sp2(sp);
	std::cout << "sp2 : " << sp2 << std::endl;

	std::cout << "=== assignation operator ===" << std::endl;
	Span sp3(3);
	sp3.addNumber(-1);
	sp3.addNumber(2);
	sp3.addNumber(5);
	std::cout << "before sp3 : " << sp3;
	sp3 = sp2;
	std::cout << "after sp3  : " << sp3 << std::endl;

	// exception
	std::cout << "======== exception ========" << std::endl;
	try {
		Span sp4(1);
		sp4.addNumber(1);
		//sp4.shortestSpan();
		//sp4.longestSpan();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "======== exception ========" << std::endl;
	try {
		sp.addNumber(5);
		sp.addNumber(20);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
/*
	// etc
	try {
		Span sp4(10000);
		srand((unsigned int)time(NULL));
		while (sp4.getArr().size() <= 10000)
		{
			sp4.addNumber((int)rand() % 20000);
		}
		std::cout << sp4 << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
*/
	return 0;
}
