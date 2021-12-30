/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:38:20 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 12:35:39 by hyojang          ###   ########.fr       */
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
	delete [] zom_arr;

	return (0);
}
