/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:48:27 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 01:37:34 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

// Constructor
Scalar::Scalar() {}
Scalar::Scalar(std::string str)
{
    this->value = str;
}

Scalar::Scalar(const Scalar &s)
{
    this->value = s.value;
}

// Assignation operator overload
Scalar& Scalar::operator = (const Scalar &s)
{
    this->value = s.value;
}

// Destructor
Scalar::~Scalar() {}

char    Scalar::convertChar(std::string str)
{
    const char *tmp = str.c_str();
    char result;
    
    result = (char)atoi(tmp);
    delete tmp;
    if (result > CHAR_MAX || result < CHAR_MIN)
        throw ImpossibleException();
    if (isprint(result) != 0)
        throw ConvertCharException();
    return (result);
}

int		Scalar::convertInt(std::string str)
{
    const char *tmp = str.c_str();
    long result;

    result = atoi(tmp);
    delete tmp;
    if (result > INT_MAX || result < INT_MIN)
        throw ConvertIntException();
    return (result);
}

float	Scalar::convertFloat(std::string str)
{
    
}

double	Scalar::convertDouble(std::string str)
{
    
}

// Exception
const char* Scalar::ImpossibleException::what() const throw()
{
    return ("impossible");
}

const char* Scalar::ConvertCharException::what() const throw()
{
    return ("Non displayable");
}

const char* Scalar::ConvertIntException::what() const throw()
{
    return ("Non displayable");
}