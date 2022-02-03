/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 19:02:26 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// stack
	ScavTrap a("stackA");
	a.status();

	// heap
	ScavTrap *b = new ScavTrap("heapB");
	b->status();

	// parent class test
	std::cout << std::endl << "1-1) attack test(override) ============" << std::endl;
	std::string target = "enemy";
	b->attack(target);
	b->status();

	// damage test
	std::cout << std::endl << "1-2) damage test ======================" << std::endl;
	b->takeDamage(200);
	b->status();
	b->takeDamage(10);
	b->status();

	// repaire test
	std::cout << std::endl << "1-3) repaire test(override) ===========" << std::endl;
	b->beRepaired(30);
	b->status();
	b->beRepaired(500);
	b->status();

	// child class test
	std::cout << std::endl << "2) guardGate test =====================" << std::endl;
	b->guardGate();
	b->status();
	b->guardGate();
	b->status();

	delete b;
	
	return 0;
}
