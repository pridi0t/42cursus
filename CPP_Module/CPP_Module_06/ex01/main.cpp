/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:24:02 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 10:29:52 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdint.h>
#include <iomanip>

typedef struct {
    std::string str;
    int dday;
} Data;

uintptr_t serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

void test()
{
    Data a = {"Resurrection like a dog", 3};
    uintptr_t src = serialize(&a);
    Data *dst = deserialize(src);
    
    std::cout << std::setw(10) << std::left << "&a" << ": " << &a << std::endl;
    std::cout << std::setw(10) << std::left << "src" << ": " << src << std::endl;
    std::cout << std::setw(10) << std::left << "dst" << ": " << dst << std::endl;

    std::cout << "=============== result ===============" << std::endl;
    std::cout << std::setw(10) << std::left << "a.str" << ": " << a.str << std::endl;
    std::cout << std::setw(10) << std::left << "a.dday" << ": " << a.dday << std::endl;
    std::cout << std::setw(10) << std::left << "dst->str" << ": " << dst->str << std::endl;
    std::cout << std::setw(10) << std::left << "dst->dday" << ": " << dst->dday << std::endl;
}

int main(void)
{
    test();
    
    return 0;
}