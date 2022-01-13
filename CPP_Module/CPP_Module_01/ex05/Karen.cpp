/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:09:19 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/13 15:42:43 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

void	Karen::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::etc(void)
{
	std::cout << "[ ETC ]" << std::endl << "No such level" << std::endl;
}

void	Karen::complain(std::string level)
{
	int			i = 0;
	std::string	str[5] = {"debug", "info", "warning", "error", "etc"};
	void		(Karen::*farr[5])(void) = { &Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::etc};
	void		(Karen::*fptr)(void);

	while (level != str[i] && i < 4)
		i++;
	fptr = farr[i];
	(this->*(fptr))();
}
