/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:24:31 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 09:07:53 by hyojang          ###   ########.fr       */
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
	std::cout << "1) If the number of elements is 1" << std::endl;
	try {
		Span sp4(1);
		sp4.addNumber(1);
		//std::cout << sp4.shortestSpan() << std::endl;
		//std::cout << sp4.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "2) If storage capacity is exceeded" << std::endl;
	try {
		sp.addNumber(5);
		sp.addNumber(20);
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	// etc
	/*
	Span sp4(10000);
	int num;

	srand((unsigned int)time(NULL));
	while (sp4.getArr().size() < 10000)
	{
		num = (rand() % 20000);
		sp4.addNumber(num);
	}
	std::cout << sp4 << std::endl;
	std::cout << sp4.shortestSpan() << std::endl;
	std::cout << sp4.longestSpan() << std::endl;
	*/
	return 0;
}
