/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:57:48 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 09:17:23 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// subject
	//Animal ani;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	// test
	std::cout << "========== create ==========" << std::endl;
	Animal *a[10];

	for (int i = 0 ; i < 2 ; i++)
		a[i] = new Dog();
	for (int i = 2 ; i < 4 ; i++)
		a[i] = new Cat();

	std::cout << "========== before ==========" << std::endl;
	Dog *da;
	Cat *ca;
	for (int i = 0 ; i < 2 ; i++)
	{
		da = dynamic_cast<Dog *>(a[i]);
		da->printBrain();
		std::cout << std::endl;
	}
	for (int i = 2 ; i < 4 ; i++)
	{
		ca = dynamic_cast<Cat *>(a[i]);
		ca->printBrain();
		std::cout << std::endl;
	}

	da->setBr(0, "a");
	ca->setBr(0, "b");

	std::cout << "========== after ==========" << std::endl;
	for (int i = 0 ; i < 2 ; i++)
	{
		da = dynamic_cast<Dog *>(a[i]);
		da->printBrain();
		std::cout << std::endl;
	}
	for (int i = 2 ; i < 4 ; i++)
	{
		ca = dynamic_cast<Cat *>(a[i]);
		ca->printBrain();
		std::cout << std::endl;
	}

	// delete
	for (int i = 0 ; i < 4 ; i++)
		delete a[i];

	return 0;
}
