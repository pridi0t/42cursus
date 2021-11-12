/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:08:46 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/13 01:24:06 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = -1;
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
		std::cout << "|" << std::setw(10) << std::right << i;
		this->pbook[i].print_format_info();
	}
	std::cout << "---------------------------------------------" << std::endl;
}

int PhoneBook::check_invalid(std::string str)
{
	if ((int)str.size() != 1)
		return (-1);
	if (str[0] >= '0' && str[0] <= '7')
		return (str[0] - '0');
	return (-1);
}

void PhoneBook::search()
{
	std::string tmp;
	int input;

	if (this->cnt == 0)
	{
		std::cout << " === PHONE BOOK is empty ===" << std::endl;
		return ;
	}
	print_table();
	std::cout << "input index(~ " << (this->cnt - 1) << ") : ";
	if (std::getline(std::cin, tmp) == NULL)
	{
		std::cout << std::endl;
		exit(1);
	}
	input = check_invalid(tmp);
	if (input < 0 || input >= this->cnt)
	{
		std::cout << "=== invalid index ===" << std::endl;
		return ;
	}
	this->pbook[input].print_info();
}
