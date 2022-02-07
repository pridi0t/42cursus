/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:21:41 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:40:04 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
		// Constructor
		Dog();
		Dog(const Dog &d);
		
		// Assignation operator overload
		Dog& operator = (const Dog &d);

		// Destructor
		virtual ~Dog();

		void makeSound() const;
};

# endif
