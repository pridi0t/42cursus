/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:28:56 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 15:52:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	private:
		// Forbidden Constructor
		PresidentialPardonForm();

	public:
		// Constructor
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		
		// Assignation operator overload
		PresidentialPardonForm& operator = (const PresidentialPardonForm &p);

		// Destructor
		virtual ~PresidentialPardonForm();

		// Static member function
		static Form *create(std::string &target);

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
