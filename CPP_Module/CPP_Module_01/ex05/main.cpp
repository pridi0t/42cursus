/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:23 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/13 15:41:42 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(void)
{
	Karen karen;

	karen.complain(" ");
	karen.complain("error");
	karen.complain("warning");
	karen.complain("info");
	karen.complain("debug");
	
	return (0);
}
