/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:17:05 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 08:59:51 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		// Constructor
		Cure();
		Cure(const Cure &c);

		// Assignation operator overload
		Cure& operator = (const Cure &c);

		// Destructor
		~Cure();

		// Override
		AMateria* clone() const;
		void use(ICharacter& target);
};

# endif
