/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 11:53:29 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 12:47:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *zom_arr = new Zombie[N];

	for (int i = 0 ; i < N ; i++){
		zom_arr[i] = new Zombie((name + std::to_string(i)));
	}

	return (zom_arr);
}
