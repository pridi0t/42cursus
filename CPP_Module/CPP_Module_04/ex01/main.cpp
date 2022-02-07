/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:57:48 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:37:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Dog *a = new Dog();
	Dog *b = new Dog(*a);

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	a->setBr(0, "a");
	std::cout << "========== A ==========" << std::endl;
	a->printBrain();

	std::cout << std::endl << "========== B ==========" << std::endl;
	b->printBrain();

	*a = *b;

	b->setBr(0, "b");
	std::cout << "========== A ==========" << std::endl;
	a->printBrain();

	std::cout << std::endl << "========== B ==========" << std::endl;
	b->printBrain();
	delete a;
	delete b;

/*
	Animal *a = new Animal[5];

	for (int i = 0 ; i < 5 ; i++)
	{
		a[i] = new Cat();
		std::cout << a[i]->getType() << std::endl;
	}
	
	delete[] a;
*/

	/*
	Brain a;
	Brain b(a);

	a.setBr(0, "a");
	std::cout << "========== A ==========" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		std::cout << a.getBr(i) << " ";
		if (i % 10 == 9)
			std::cout << std::endl;
	}
	
	std::cout << "========== B ==========" << std::endl;
	for (int i = 0 ; i < 100 ; i++)
	{
		std::cout << b.getBr(i) << " ";
		if (i % 10 == 9)
			std::cout << std::endl;
	}
	*/
	return 0;
}
