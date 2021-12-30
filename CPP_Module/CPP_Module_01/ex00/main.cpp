/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 17:38:20 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 22:02:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *heap_zombie = newZombie("heap_zombie");

	heap_zombie->Announce();
	randomChump("stack_zombie");
	delete heap_zombie;

	return (0);
}
