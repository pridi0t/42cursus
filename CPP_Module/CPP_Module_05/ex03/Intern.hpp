/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:05:53 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 14:55:02 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"

class Intern {
	public:
		// Constructor
		Intern();
		Intern(const Intern &i);
		
		// Assignation operator overload
		Intern& operator = (const Intern &i);

		// Destructor
		~Intern();
		
		Form *makeForm(std::string fname, std::string target);
		
		// Exception Class
		class FormNotFoundException : public std::exception {
			public:
				const char* what() const throw();
		};
};

# endif
