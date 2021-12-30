/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:38:20 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 21:56:00 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int		count;
	Zombie	*zom_arr;

	std::cout << "N : ";
	std::cin >> count;

	zom_arr = zombieHorde(count, "zombie");
	std::cout << "zom_arr = " << zom_arr << std::endl;
	delete [] zom_arr;

	return (0);
}
