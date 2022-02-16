/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:53:17 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 16:09:50 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
    srand((unsigned int)time(NULL));
    std::cout << "before : ";
    if (rand() % 3 == 0)
    {
        std::cout << "A" << std::endl;
        return (static_cast<Base *>(new A()));
    }
    else if (rand() % 3 == 1)
    {
        std::cout << "B" << std::endl;
        return (static_cast<Base *>(new B()));
    }
    else
    {
        std::cout << "C" << std::endl;
        return (static_cast<Base *>(new C()));
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception & e) {
        try {
            (void)dynamic_cast<B &>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception & e) {
            std::cout << "C" << std::endl;
        }
    }
}

void test()
{
    Base *tmp;

    tmp = generate();
    std::cout << "ptr after : ";
    identify(tmp);
    std::cout << "ref after : ";
    identify(*tmp);
    delete tmp;
}

int main(void)
{
    test();
    return 0;
}