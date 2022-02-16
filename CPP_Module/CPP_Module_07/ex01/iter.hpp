/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:57:29 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/16 14:21:50 by hyojang          ###   ########.fr       */
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