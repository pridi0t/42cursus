/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:48:27 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 07:05:13 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

// Constructor
Scalar::Scalar() {}
Scalar::Scalar(std::string str)
{
    const char *tmp = str.c_str();
    this->dvalue = atof(tmp);
    std::string result;
    std::ostringstream convert;
    
    this->value = str;
    convert << this->dvalue;
    result = convert.str();
    if (result.compare(this->value) != 0)
    {
        result += "f";
        if (result.compare(this->value) != 0)
            throw ImpossibleException();
    }
}

Scalar::Scalar(const Scalar &s)
{
    this->value = s.value;
    this->dvalue = s.dvalue;
}

// Assignation operator overload
Scalar& Scalar::operator = (const Scalar &s)
{
    this->value = s.value;
    this->dvalue = s.dvalue;
    return (*this);
}

// Destructor
Scalar::~Scalar() {}

// getter
std::string Scalar::getStr() const
{
    return (this->value);
}

double Scalar::getDouble() const
{
    return (this->dvalue);
}

/*
// overload
bool	Scalar::checkSame(double dnum)
{
    std::string result;
    std::ostringstream convert;
    
    convert << dnum;
    result = convert.str();
    if (result.compare(this->value) != 0)
        return (false);
    return (true);
}

bool	Scalar::checkSame(float fnum)
{
    std::string result;
    std::ostringstream convert;
    
    convert << fnum;
    result = convert.str();
    if (result.compare(this->value) != 0)
    {
        result += "f";
        if (result.compare(this->value) != 0)
        {
            std::cout << "dddd" << result.compare(this->value) << std::endl;
            return (false);
        }
        return (true);
    }
    return (true);
}
*/

char    Scalar::convertChar(double dvalue)
{
    int result = static_cast<int>(dvalue);

    //if (checkSame(dvalue) == false)
        //throw ImpossibleException();
    if (result > CHAR_MAX || result < CHAR_MIN)
        throw ImpossibleException();
    if (isprint(result) == 0)
        throw NonDisplayableException();
    return ((char)result);
}

int		Scalar::convertInt(double dvalue)
{
    long result = static_cast<long>(dvalue);
    
    //if (checkSame(dvalue) == false)
        //throw ImpossibleException();
    if (result > INT_MAX || result < INT_MIN)
        throw ImpossibleException();
    return ((int)result);
}

float	Scalar::convertFloat(double dvalue)
{
    float result = static_cast<float>(dvalue);
    
    //if (checkSame(result) == false)
        //throw ImpossibleException();
    if (result > FLT_MAX || result < -FLT_MIN)
        throw ImpossibleException();
    return (result);    
}

double  Scalar::convertDouble(double dvalue)
{
    //if (checkSame(dvalue) == false)
        //throw ImpossibleException();
    return (dvalue);
}

// Exception
const char* Scalar::ImpossibleException::what() const throw()
{
    return ("impossible");
}

const char* Scalar::NonDisplayableException::what() const throw()
{
    return ("Non displayable");
}

// ostream overload
std::ostream& operator << (std::ostream& os, Scalar &s)
{
    try {
        std::string str = "'";
        os << "char : ";
        str += s.convertChar(s.getDouble());
        os << str << "'" << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }
    
    try {
        os << "int : " << s.convertInt(s.getDouble()) << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }

    try {
        os << "float : ";
        float tmp = s.convertFloat(s.getDouble());
        os << tmp;
        if ((tmp - static_cast<int>(tmp)) == 0)
            os << ".0f";
        else
            os << "f";
        os << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }

    try {
        os << "double : " << s.convertDouble(s.getDouble()) << std::endl; 
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }
    
    return (os);
}