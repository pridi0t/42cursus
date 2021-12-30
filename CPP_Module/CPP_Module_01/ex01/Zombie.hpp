/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:48 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 12:48:39 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

#include <iostream>
#include <cstring>

class Zombie {
	private:
		std::string	name;
		void		Announce();
	public:
		Zombie(std::string name);
		~Zombie();
};

Zombie	*zombieHorde(int N, std::string name);

# endif
