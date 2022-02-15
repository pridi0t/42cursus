/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:48:27 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 00:36:43 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

// Constructor
Scalar::Scalar() {}
Scalar::Scalar(std::string arg)
{}

Scalar::Scalar(const Scalar &s)
{}

// Assignation operator overload
Scalar& Scalar::operator = (const Scalar &s)
{}

// Destructor
Scalar::~Scalar() {}

char    Scalar::convertChar(std::string str)
{}

int		Scalar::convertInt(std::string str)
{}

float	Scalar::convertFloat(std::string str)
{}

double	Scalar::convertDouble(std::string str)
{}