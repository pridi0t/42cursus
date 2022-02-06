/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:31:41 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 05:36:47 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		// Constructor
		WrongCat();
		WrongCat(const WrongCat &w);
		
		// Assignation operator overload
		WrongCat& operator = (const WrongCat &c);

		// Destructor
		~WrongCat();

		void makeSound() const;
};

# endif
