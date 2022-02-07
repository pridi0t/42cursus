/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:52:12 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 01:55:05 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		// Constructor
		Animal();
		Animal(const Animal &a);
		
		// Assignation operator overload
		Animal& operator = (const Animal &a);

		// Destructor
		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

# endif
