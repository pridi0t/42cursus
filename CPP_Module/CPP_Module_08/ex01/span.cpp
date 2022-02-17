/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:25:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 03:12:27 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// Constructor
Span::Span() {};
Span::Span(unsigned int n)
{
	this->arr_max = n;
	this->arr.clear();
}

Span::Span(const Span &s)
{
	this->arr_max = s.arr_max;
	this->arr.clear();
	for (std::set<int>::iterator iter = s.begin() ; i != s.end() ; i++)
		this->arr.insert(*i);
}

// Assignation operator overload
Span& Span::operator = (const Span &s)
{
	if (this != &s) {
		this->arr_max = s.arr_max;
		this->arr.clear();
		for (std::set<int>::iterator iter = s.begin() ; i != s.end() ; i++)
			this->arr.insert(*i);
	}
	return (*this);
}

// Destructor
Span::~Span() {}

void	Span::addNumber(int num)
{
	if (this->arr.size() == this->arr_max)
		throw InsetException();
	this->arr.insert(num);
}

long long	Span::shortestSpan()
{
	if (this->arr.size() <= 1)
		throw FindException();
	
}

long long	Span::longestSpan()
{
	std::set<int>::iterator min;
	std::set<int>::iterator max;
	
	if (this->arr.size() <= 1)
		throw FindException();
	min = this->arr.begin();
	max = this->arr.end();
	--max;
	return ((long long)*max - (long long)*min);
}
