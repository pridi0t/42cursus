/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 04:37:14 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 08:42:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		std::string	name;
		AMateria	*inven[4];
		int			inven_size;

	public:
		// Constructor
		Character();
		Character(std::string name);
		Character(const Character &c);

		// Assignation operator overload
		Character& operator = (const Character &c);

		// Destructor
		~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

# endif
