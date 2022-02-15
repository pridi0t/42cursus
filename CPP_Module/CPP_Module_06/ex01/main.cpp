/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:24:02 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 09:37:54 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
//#include <cstdint>
#include <cassert>

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

int main(void)
{
    Data a = {"Resurrection like a dog", 3};
    uintptr_t src = serialize(&a);
    Data *dst = deserialize(src);
    

    std::cout << "&a : " << &a << std::endl;
    std::cout << "src : " << src << std::endl;
    std::cout << "dst : " << dst << std::endl;
    
    return 0;
}