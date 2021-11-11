/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:08:46 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 01:16:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class PhoneBook {
	private:
		int index;
		int cnt;
		Contact pbook[8];
	
	public:
		add();
		search();
};

void PhoneBook::PhoneBook()
{
	// add initialize pbook?
	this.index = 0;
	this.cnt = 0;
}

void PhoneBook::add()
{
	this.index++;
	if (this.index >= 8)
		this.index %= 8;
	
	if (this.cnt == 8)
	{
		this.pbook[this.index].init_info();
		this.pbook[this.index].input_info();
	}
	else
	{
		Contact contact;
		contact.input_info();
		this.pbook[this.index] = contact;
		this.cnt++;
	}
}

int main()
{
	std::string input;
	PhoneBook phone_book;

	while (1)
	{
		std::cout << "input command[ADD, SEARCH, EXIT] : ";
		if (std::getline(std::cin, input) == NULL)
			exit(1);
		if (input.compare("ADD") == 0)
			phone_book::add();
		else if (input.compare("SEARCH") == 0)
			//
		else if (input.compare("EXIT") == 0)
			return 0;
		else
			std::cout << " === invalid command :( ===" << std::endl;
	}
	return 0;
}
