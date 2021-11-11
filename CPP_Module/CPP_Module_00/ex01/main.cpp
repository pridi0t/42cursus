/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 01:45:30 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 05:09:17 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string input;
	PhoneBook phone_book;

	while (1)
	{
		std::cout << "input command[ADD, SEARCH, EXIT] : ";
		
		if (std::getline(std::cin, input) == NULL)
		{
			std::cout << std::endl;
			exit(1);
		}
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(1);
		}

		if (input.compare("ADD") == 0)
			phone_book.add();
		else if (input.compare("SEARCH") == 0)
			phone_book.search();
		else if (input.compare("EXIT") == 0)
			break ;
		else
			std::cout << " === ): invalid command :( ===" << std::endl;
	}
	return 0;
}
