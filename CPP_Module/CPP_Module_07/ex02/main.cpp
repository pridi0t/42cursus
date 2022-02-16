/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:44 by marvin            #+#    #+#             */
/*   Updated: 2022/02/16 01:49:30 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(void)
{
    Array<char> a;
    std::cout << "a size : " << a.getLen() << std::endl;

    std::string str = "01234";
    Array<std::string> b(5);
    
    for (int i = 0 ; i < 5 ; i++) {
        b[i] = str.substr(0, i);
    }
    std::cout << "b size : " << b.getLen() << std::endl;
    for (int i = 0 ; i < (int)b.getLen() ; i++) {
        std::cout << "b[" << i << "] : " << b[i] << std::endl; 
    }

    std::cout << "-------- copy test --------" << std::endl;
    const Array<std::string> copy_b = b;
    
    b[0] = "bbbbbbbbbbbbbb";
    std::cout << "b size : " << b.getLen() << std::endl;
    for (int i = 0 ; i < (int)b.getLen() ; i++) {
        std::cout << "b[" << i << "] : " << b[i] << std::endl; 
    }
    
    std::cout << "copy_b size : " << copy_b.getLen() << std::endl;
    for (int i = 0 ; i < (int)copy_b.getLen() ; i++) {
        std::cout << "copy_b[" << i << "] : " << copy_b[i] << std::endl; 
    }
    
    //exception test
    try {
        b[6];
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}