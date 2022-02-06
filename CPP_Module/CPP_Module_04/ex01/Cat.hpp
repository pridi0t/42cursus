/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:40:35 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 06:42:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	private:
		

	public:
		// Constructor
		Cat();
		Cat(const Cat &c);
		
		// Assignation operator overload
		Cat& operator = (const Cat &c);

		// Destructor
		~Cat();

		void makeSound() const;
};

# endif
