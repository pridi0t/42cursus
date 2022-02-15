/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:29 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 23:11:34 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *arr, int len, void (*fptr)(const T&))
{
    for (int i = 0 ; i < len ; i++)
    {
        (*fptr)(arr[i]);
    }
}

# endif
