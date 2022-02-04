/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:11:55 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 02:59:17 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string name;

	public:
		// Constructor
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &d);

		// Assignation operator overload
		DiamondTrap& operator = (const DiamondTrap &d);

		// Destructor
		~DiamondTrap();

		void whoAmI();
};

# endif
