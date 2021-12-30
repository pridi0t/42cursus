/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:48 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/31 00:38:26 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <cstring>

class Zombie {
	private:
		std::string	name;
		static int num;
	public:
		Zombie();
		~Zombie();
		void		Announce();
		void		setName(std::string name);
};

Zombie		*zombieHorde(int N, std::string name);

# endif
