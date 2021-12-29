/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:48 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/29 18:07:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

#include <iostream>

class Zombie {
	private:
		std::string	name;
		void		Announce();
	public:
		Zombie(std::string name);
		~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

# endif
