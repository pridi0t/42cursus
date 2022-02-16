/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 17:19:52 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T x)
{
	std::cout << x << " ";
}

int main(void)
{
    int tab[] = {0, 1, 2, 3, 4};
    iter(tab, 5, print);
	std::cout << std::endl;
    
	char a[] = {'a', 'b'};
    iter (a, 2, print);
	std::cout << std::endl;
    
	double b[] = {1.2, 2.3};
    iter (b, 2, print);
	std::cout << std::endl;
    
    return 0;
}