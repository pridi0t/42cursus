/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:24:16 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/08 05:54:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string	br[100];
		int			size_br;

	public:
		// Constructor
		Brain();
		Brain(const Brain &b);
		
		// Assignation operator overload
		Brain& operator = (const Brain &b);

		// Destructor
		~Brain();

		std::string getBr(int index) const;
		void setBr(int index, std::string value);
		int getSizeBr() const;
};

# endif
