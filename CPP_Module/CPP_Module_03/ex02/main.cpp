/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/06 02:35:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	// stack
	FragTrap a("stackA");
	a.status();

	// heap
	FragTrap *b = new FragTrap("heapB");
	b->status();

	// parent class test
	std::cout << std::endl << "ClapTrap test ======================" << std::endl;
	a.takeDamage(10);
	a.status();
	a.beRepaired(200);
	a.status();

	// child class test
	std::cout << std::endl << "FragTrap test ======================" << std::endl;
	a.attack("enemy");
	a.status();
	b->highFivesGuys();

	delete b;

	return 0;
}
