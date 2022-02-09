/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:47:08 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 07:56:13 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string type;

	public:
		// Constructor
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria &a);

		// Assignation operator overload
		AMateria& operator = (const AMateria &a);

		// Destructor
		virtual ~AMateria();

		std::string const & getType() const;
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

# endif
