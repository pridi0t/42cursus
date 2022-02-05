/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 23:29:01 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	// stack
	DiamondTrap a("stackA");
	a.status();

	// parent class test
	std::cout << std::endl << "1-1) ClapTrap test ======================" << std::endl;
	a.takeDamage(10);
	a.status();
	a.beRepaired(200);
	a.status();
	
	std::cout << std::endl << "1-2) ScavTrap test ======================" << std::endl;
	a.attack("enemy");
	a.status();
	a.guardGate();

	std::cout << std::endl << "1-3) FragTrap test ======================" << std::endl;
	a.highFivesGuys();
	
	// child class test
	std::cout << std::endl << "DiamondTrap test ======================" << std::endl;
	a.whoAmI();

	return 0;
}
