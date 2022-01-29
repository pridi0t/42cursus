/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:09:19 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/29 14:20:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I just love it" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon cost more money." << std::endl << " You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::etc(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Karen::complain(std::string level)
{
	int			i = 0;
	std::string	str[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "ETC"};
	void		(Karen::*farr[5])(void) = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::etc};

	while (level != str[i] && i < 4)
		i++;
	switch (i) {
		case 0:
			(this->*(farr[0]))();
			std::cout << std::endl;
		case 1:
			(this->*(farr[1]))();
			std::cout << std::endl;
		case 2:
			(this->*(farr[2]))();
			std::cout << std::endl;
		case 3:
			(this->*(farr[3]))();
			std::cout << std::endl;
			break;
		default:
			(this->*(farr[4]))();
			std::cout << std::endl;
	}
}
