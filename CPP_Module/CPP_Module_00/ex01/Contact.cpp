/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:42:16 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 05:18:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::input_string(std::string &str, std::string notice)
{
	int i;

	while (1)
	{
		std::cout << notice << " : ";
		if (getline(std::cin, str) == NULL)
		{
			std::cout << std::endl;
			exit(1);
		}
		if (str.size() > 0)
		{
			i = -1;
			while (++i < (int)str.size())
			{
				if (isalpha(str[i]) == 0 && str[i] != ' ')
					break ;
			}
			if (i == (int)str.size())
				return ;
		}
		str.clear();
		std::cout << " --- invalid value --- " << std::endl;
	}
}

void Contact::input_phone_number(std::string &str, std::string notice)
{
	int i;

	while (1)
	{
		std::cout << notice << "(only number) : ";
		if (getline(std::cin, str) == NULL)
		{
			std::cout << std::endl;
			exit(1);
		}
		if (str.size() > 0)
		{
			i = -1;
			while (++i < (int)str.size())
			{
				if (isdigit(str[i]) == 0)
					break;
			}
			if (i == (int)str.size() && i == 11)
				return ;
		}
		str.clear();
		std::cout << " --- invalid value --- " << std::endl;
	}
}

void Contact::cut_string(std::string str)
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void Contact::init_info()
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}

void Contact::input_info()
{
	Contact::input_string(this->first_name, "first name");
	Contact::input_string(this->last_name, "last name");
	Contact::input_string(this->nickname, "nickname");
	Contact::input_phone_number(this->phone_number, "phone number");
	Contact::input_string(this->darkest_secret, "darkest_secret");
}

void Contact::print_format_info()
{
	std::cout << "|";
	cut_string(this->first_name);
	std::cout << "|";
	cut_string(this->last_name);
	std::cout << "|";
	cut_string(this->nickname);
	std::cout << "|" << std::endl;
}

void Contact::print_info()
{
	std::cout << "first name : " << this->first_name << std::endl;
	std::cout << "last name : " << this->last_name << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phone number : " << this->phone_number.substr(0, 3) << "-" << this->phone_number.substr(3, 4) << "-" << this->phone_number.substr(7, 4) << std::endl;
	std::cout << "darkest_secret : " << this->darkest_secret << std::endl;
}
