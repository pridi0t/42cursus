/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 19:49:40 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Test {
	private:
		int num;
	public:
		Test() { this->num = 1; };
		int getNum() const { return (this->num); }
};

std::ostream & operator << (std::ostream &o, const Test &t)
{
	o << t.getNum() << " ";
	return (o);
}

template <typename T>
void print(T x)
{
	std::cout << x << " ";
}

int main(void)
{
    int a[] = {0, 1, 2, 3, 4};
    iter(a, 5, print);
	std::cout << std::endl;
    
	char b[] = {'a', 'b'};
    iter (b, 2, print);
	std::cout << std::endl;
    
	double c[] = {1.2, 2.3};
    iter (c, 2, print);
	std::cout << std::endl;

	Test d[10];
	iter (d, 10, print);
    
    return 0;
}