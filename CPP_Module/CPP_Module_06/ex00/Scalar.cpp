/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:48:27 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 08:06:03 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

// Constructor
Scalar::Scalar() {}
Scalar::Scalar(std::string str)
{
    try {
        this->original_value = str;
        this->dvalue = stod(str);
    } catch (std::exception & e) {
        throw ConstructorException();
    }
}

Scalar::Scalar(const Scalar &s)
{
    this->original_value = s.original_value;
    this->dvalue = s.dvalue;
}

// Assignation operator overload
Scalar& Scalar::operator = (const Scalar &s)
{
    this->original_value = s.original_value;
    this->dvalue = s.dvalue;
    return (*this);
}

// Destructor
Scalar::~Scalar() {}

// getter
std::string Scalar::getOriginal() const
{
    return (this->original_value);
}

double Scalar::getDvalue() const
{
    return (this->dvalue);
}

char    Scalar::convertChar(double dvalue)
{
    int result = static_cast<int>(dvalue);

    if (result > CHAR_MAX || result < CHAR_MIN)
        throw ImpossibleException();
    if (isprint(result) == 0)
        throw NonDisplayableException();
    return (static_cast<char>(result));
}

int		Scalar::convertInt(double dvalue)
{
    long result = static_cast<long>(dvalue);

    if (result > INT_MAX || result < INT_MIN)
        throw ImpossibleException();
    return (static_cast<int>(result));
}

float	Scalar::convertFloat(double dvalue)
{
    float result;
    
    try {
        result = static_cast<float>(dvalue);
    } catch (std::exception & e) {
        throw ImpossibleException();
    }
    return (result);
}

// Exception
const char* Scalar::ConstructorException::what() const throw() 
{
    return ("[Error] Constructor Exception");
}

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
        str += s.convertChar(s.getDvalue());
        os << str << "'" << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }
    
    try {
        os << "int : " << s.convertInt(s.getDvalue()) << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }

    try {
        os << "float : ";
        float ftmp = s.convertFloat(s.getDvalue());
        os << ftmp;
        if ((ftmp - static_cast<int>(ftmp)) == 0)
            os << ".0f";
        else
            os << "f";
        os << std::endl;
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }

    try {
        os << "double : ";
        double dtmp = s.getDvalue();
        os << dtmp;
        if ((dtmp - static_cast<int>(dtmp)) == 0)
            os << ".0";
        os << std::endl; 
    } catch (std::exception & e) {
        os << e.what() << std::endl;
    }
    
    return (os);
}