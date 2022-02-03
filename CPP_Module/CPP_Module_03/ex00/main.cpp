/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 11:23:19 by hyojang          ###   ########.fr       */
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
	
	return 0;
}
