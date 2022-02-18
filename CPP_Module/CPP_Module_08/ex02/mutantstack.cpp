/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:13:00 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 14:09:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

// Constructor
template <typename T>
MutantStack<T>::MutantStack() : MutantStack<T>::stack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &m) : MutantStack<T>::stack(m)
{}

// Assignation operator overload
template <typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack<T> &m)
{
	if (this != &m) {
		MutantStack<T>::stack::operator=(m);
	}
	return (*this);
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack() {}

// Iterator
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}
