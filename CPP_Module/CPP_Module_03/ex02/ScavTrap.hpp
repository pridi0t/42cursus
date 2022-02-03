/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:31:16 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/03 18:46:13 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		int	mode;

	public:
		// Constructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &s);

		// Assignation operator overload
		ScavTrap& operator = (const ScavTrap &s);

		// Destructor
		~ScavTrap();

		// override
		void attack(std::string const & target);
		void beRepaired(unsigned int amount);
		void status();

		void guardGate();
};

# endif
