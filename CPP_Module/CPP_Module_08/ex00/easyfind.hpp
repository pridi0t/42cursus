/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:54:58 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/17 22:23:46 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind (T &container, int i)
{
	typename T::iterator iter;
	
	iter = std::find(container.begin(), container.end(), i);
	if (iter == container.end()) {
		throw std::exception();
	}
	return (iter);
}

# endif