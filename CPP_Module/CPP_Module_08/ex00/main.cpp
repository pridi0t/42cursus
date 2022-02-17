/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:55:18 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 00:06:03 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <set>

int main()
{
	// Vector test
	std::cout << "---------- vector ----------" << std::endl;
	std::vector<int> a;
	for (int i = 0 ; i < 5 ; i++)
		a.push_back(i);

	std::cout << "[vector] : ";
	for (std::vector<int>::iterator i = a.begin() ; i < a.end() ; i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	try {
		std::vector<int>::iterator iter1;
		iter1 = easyfind(a, 1);
		std::cout << "easyfind(a, 1) : " << *iter1 << std::endl;
		iter1 = easyfind(a, 5);
		std::cout << "easyfind(a, 5) : " << *iter1 << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	// Set test
	std::cout << "----------- set ------------" << std::endl;
	std::set<int> b;
	for (int i = 0 ; i < 5 ; i++)
		b.insert(i);

	std::cout << "[set] : ";
	for (std::set<int>::iterator i = b.begin() ; i != b.end() ; i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	try {
		std::set<int>::iterator iter2;
		iter2 = easyfind(b, 2);
		std::cout << "easyfind(b, 2) : " << *iter2 << std::endl;
		iter2 = easyfind(b, -1);
		std::cout << "easyfind(b, -1) : " << *iter2 << std::endl;
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}