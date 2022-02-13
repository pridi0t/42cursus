/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 07:10:04 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 14:39:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern	someRandomIntern;
	Form*	rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	return 0;
}
