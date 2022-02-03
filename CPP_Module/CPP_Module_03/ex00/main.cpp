/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 14:22:21 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	// stack
	ClapTrap a("stackA");
	a.status();

	// heap
	ClapTrap *b = new ClapTrap("heapB");
	b->status();
	delete b;

	// attack test
	std::cout << std::endl << "1. attack test ======================" << std::endl;
	std::string target = "enemy";
	a.attack(target);
	a.status();

	// damage test
	std::cout << std::endl << "2. damage test ======================" << std::endl;
	a.takeDamage(5);
	a.status();
	a.takeDamage(10);
	a.status();

	// repaire test
	std::cout << std::endl << "3. repaire test =====================" << std::endl;
	a.beRepaired(3);
	a.status();
	a.beRepaired(20);
	a.status();

	return 0;
}
