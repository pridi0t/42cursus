/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:21:41 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:42:46 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *db;

	public:
		// Constructor
		Dog();
		Dog(const Dog &d);
		
		// Assignation operator overload
		Dog& operator = (const Dog &d);

		// Destructor
		virtual ~Dog();

		// Override
		void makeSound() const;

		Brain getBr() const;
		void setBr(int index, std::string value);
		void printBrain();
};

# endif
