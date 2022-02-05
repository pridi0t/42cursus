/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:31:16 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 21:53:25 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define S_HP	100
#define S_EP	50
#define S_DMG	20

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
		void status();

		void guardGate();
};

# endif
