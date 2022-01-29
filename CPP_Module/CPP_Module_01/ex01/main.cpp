/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:38:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/29 11:21:42 by hyojang          ###   ########.fr       */
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
	for (int i = 0 ; i < count ; i++) {
		zom_arr[i].announce();
	}
	delete[] zom_arr;

	return (0);
}
