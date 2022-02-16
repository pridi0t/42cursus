/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 14:22:03 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome {
    public:
        Awesome(void) : _n(42) {return;}
        int get(void) const {return this->_n;}
        
    private:
        int _n;
};

std::ostream & operator << (std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

template <typename T>
void print (T const & x) {std::cout << x << std::endl; return;}

int main(void)
{
    int tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];

    iter(tab, 5, print);
    iter(tab2, 5, print);
    
    char a[] = {'a', 'b'};
    iter (a, 2, print);
    double b[] = {1.2, 2.3};
    iter (b, 2, print);
    
    return 0;
}