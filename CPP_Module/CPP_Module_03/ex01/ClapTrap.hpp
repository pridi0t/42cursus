/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:29:02 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 19:45:39 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap {
	protected:
		std::string		name;
		unsigned int	hitpoints;
		unsigned int	energy_points;
		unsigned int	attack_damage;

	public:
		// Constructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		
		// Assignation operator overload
		ClapTrap& operator = (const ClapTrap &c);

		// Destructor
		~ClapTrap();

		void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void status();
};

# endif
