/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:12:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/06 01:25:11 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

#define F_HP	100
#define F_EP	100
#define F_DMG	30

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

		void highFivesGuys(void);
};

# endif
