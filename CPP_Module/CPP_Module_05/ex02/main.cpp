/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 07:54:47 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try 
	{
		// constructor
		//PresidentialPardonForm a;
		PresidentialPardonForm p1("p1");
		PresidentialPardonForm p2(p1);
		
		// Assignation operator overload
		PresidentialPardonForm p3("p3");
		p2 = p3;
		
		// function test
		Bureaucrat b1("b1", 1);
		p1.execute(b1);

	} catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	return 0;
}
