/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 22:01:45 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 23:57:16 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "========== address ==========" << std::endl;
	std::cout << std::setw(10) << std::left << "str" << " : "<< &str << std::endl;
	std::cout << std::setw(10) << "stringPTR" << " : " << stringPTR << std::endl;
	std::cout << std::setw(10) << "stringREF" << " : " << &stringREF << std::endl;
	
	std::cout << "=========== value ===========" << std::endl;
	std::cout << std::setw(10) << std::left << "str" << " : "<< str << std::endl;
	std::cout << std::setw(10) << "stringPTR" << " : " << *stringPTR << std::endl;
	std::cout << std::setw(10) << "stringREF" << " : " << stringREF << std::endl;

	return (0);
}
