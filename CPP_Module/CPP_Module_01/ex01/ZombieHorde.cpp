/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:53:29 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 21:51:45 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "N must be greater than 0" << std::endl;
		return (NULL);
	}

	Zombie *zom_arr = new Zombie[N];

	for (int i = 0 ; i < N ; i++) {
		zom_arr[i].setName(name + std::to_string(i + 1));
		zom_arr[i].Announce();
	}

	return (zom_arr);
}
