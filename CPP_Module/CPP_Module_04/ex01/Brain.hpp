/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 06:24:16 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/07 06:52:09 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	privte:
		std::string br[100];

	public:
		// Constructor
		Brain();
		Brain(const Brain &b);
		
		// Assignation operator overload
		Brain& operator = (const Brain &b);

		// Destructor
		virtual ~Brain();
};

# endif
