/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 05:21:32 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 05:36:48 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;

	public:
		// Constructor
		WrongAnimal();
		WrongAnimal(const WrongAnimal &w);
		
		// Assignation operator overload
		WrongAnimal& operator = (const WrongAnimal &w);

		// Destructor
		virtual ~WrongAnimal();

		std::string getType() const;
		void makeSound() const;
};

# endif
