/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:25:50 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 03:56:41 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
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
	for (std::set<int>::iterator i = s.arr.begin() ; i != s.arr.end() ; i++)
		this->arr.insert(*i);
}

// Assignation operator overload
Span& Span::operator = (const Span &s)
{
	if (this != &s) {
		this->arr_max = s.arr_max;
		this->arr.clear();
		for (std::set<int>::iterator i = s.arr.begin() ; i != s.arr.end() ; i++)
			this->arr.insert(*i);
	}
	return (*this);
}

// Destructor
Span::~Span() {}

// getter
const std::set<int>	&Span::getArr() const
{
	return (this->arr);
}

unsigned int	Span::getArrmax() const
{
	return (this->arr_max);
}

void	Span::addNumber(int num)
{
	if (this->arr.size() == this->arr_max)
		throw InsertException();
	this->arr.insert(num);
}

long long	Span::shortestSpan()
{
	long long min_gap = LLONG_MAX;
	long long gap;
	std::set<int>::iterator last, next;

	if (this->arr.size() <= 1)
		throw FindException();
	last = --(this->arr.end());
	for (std::set<int>::iterator i = this->arr.begin() ; i != last ; i++)
	{
		next = i;
		next++;
		gap = (long long)*next - (long long)*i;
		if (gap < min_gap)
			min_gap = gap;
	}
	return (min_gap);
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

// Exception Class
const char* Span::InsertException::what() const throw()
{
	return ("[Span] Insert Exception");
}

const char* Span::FindException::what() const throw()
{
	return ("[Span] Find Exception");
}

// ostream overload
std::ostream& operator << (std::ostream& os, const Span &s)
{
	for (std::set<int>::iterator i = s.getArr().begin() ; i != s.getArr().end() ; i++)
		os << (*i) << " ";
	os << std::endl;
	return (os);
}
