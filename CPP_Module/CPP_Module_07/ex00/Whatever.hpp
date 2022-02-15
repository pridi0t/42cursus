/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:36:05 by marvin            #+#    #+#             */
/*   Updated: 2022/02/15 23:27:11 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T &n1, T &n2)
{
    T tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
}

template <typename T>
T min(const T n1, const T n2)
{
    if (n1 < n2)
        return (n1);
    return (n2);
}

template <typename T>
T max(const T n1, const T n2)
{
    if (n1 > n2)
        return (n1);
    return (n2);   
}

# endif
