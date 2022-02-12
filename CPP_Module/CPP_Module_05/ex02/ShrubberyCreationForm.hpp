/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:17:13 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 06:39:00 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		// Constructor
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		
		// Assignation operator overload
		ShrubberyCreation& operator = (const ShrubberyCreationForm &s);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
