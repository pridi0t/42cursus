/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:13:36 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 08:43:14 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		// Constructor
		Ice();
		Ice(const Ice &i);

		// Assignation operator overload
		Ice& operator = (const Ice &i);

		// Destructor
		~Ice();

		// Override
		AMateria* clone() const;
		void use(ICharacter& target);
};

# endif
