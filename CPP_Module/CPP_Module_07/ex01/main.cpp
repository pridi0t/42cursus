/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:44 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 23:10:59 by marvin           ###   ########seoul.kr  */
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
    
    return 0;
}