/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:40:35 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:39:55 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	public:
		// Constructor
		Cat();
		Cat(const Cat &c);
		
		// Assignation operator overload
		Cat& operator = (const Cat &c);

		// Destructor
		virtual ~Cat();

		void makeSound() const;
};

# endif
