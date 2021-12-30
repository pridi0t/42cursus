/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:50:48 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/30 22:02:29 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE__HPP
# define ZOMBIE__HPP

#include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void		Announce();
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

# endif
