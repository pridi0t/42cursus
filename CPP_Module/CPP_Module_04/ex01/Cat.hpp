/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 00:40:35 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 06:43:08 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *cb;

	public:
		// Constructor
		Cat();
		Cat(const Cat &c);
		
		// Assignation operator overload
		Cat& operator = (const Cat &c);

		// Destructor
		virtual ~Cat();

		// Override
		void makeSound() const;

		Brain getBr() const;
		void setBr(int index, std::string value);
		void printBrain();
};

# endif
