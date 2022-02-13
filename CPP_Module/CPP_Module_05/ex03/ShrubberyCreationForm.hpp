/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:17:13 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 15:52:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	private:
		// Forbidden Constructor
		ShrubberyCreationForm();

	public:
		// Constructor
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		
		// Assignation operator overload
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm &s);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Static member function
		static Form *create(std::string &target);

		// Override
		void	execute(Bureaucrat const & excutor) const;

		// Exception Class
		class FileWriteException : public std::exception {
			public:
				const char* what() const throw();
		};
};

# endif
