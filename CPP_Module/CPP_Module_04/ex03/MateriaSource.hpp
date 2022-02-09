/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 05:17:26 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/09 08:08:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*meta[4];
		int			meta_size;

	public:
		// Constructor
		MateriaSource();
		MateriaSource(const MateriaSource &m);

		// Assignation operator overload
		MateriaSource& operator = (const MateriaSource &m);

		// Destructor
		~MateriaSource();

		// Override
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

# endif
