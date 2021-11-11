/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:08:46 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 03:39:35 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	// add initialize pbook?
	this->index = 0;
	this->cnt = 0;
}

void PhoneBook::add()
{
	this->index++;
	if (this->index >= 8)
		this->index %= 8;
	
	if (this->cnt == 8)
	{
		this->pbook[this->index].init_info();
		this->pbook[this->index].input_info();
	}
	else
	{
		Contact contact;
		contact.input_info();
		this->pbook[this->index] = contact;
		this->cnt++;
	}
}

void PhoneBook::print_table()
{
	int i = -1;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|   index  |first name| lastname | nickname |" << std::endl;
	while (++i < this->cnt)
	{
		std::cout << "|" << std::setw(10) << std::right << this->index;
		this->pbook[i].print_format_info();
	}
	std::cout << "---------------------------------------------" << std::endl;

}

void PhoneBook::search()
{
	int input;

	if (this->cnt == 0)
	{
		std::cout << " === PHONE BOOK is empty ===" << std::endl;
		return ;
	}
	print_table();
	std::cout << "input index(0 ~ " << (this->cnt - 1) << ") : ";
	std::cin >> input;
	if (input >= this->cnt)
	{
		std::cout << "=== index not exist ===" << std::endl;
		return ;
	}
	this->pbook[input].print_info();
}
