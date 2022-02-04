/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/05 04:42:17 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		// Constructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &f);

		// Assignation operator overload
		FragTrap& operator = (const FragTrap &f);

		// Destructor
		~FragTrap();

		// override
		void attack(std::string const & target);

		void highFivesGuys(void);
};

# endif
