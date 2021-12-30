/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:48 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 21:41:41 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

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
