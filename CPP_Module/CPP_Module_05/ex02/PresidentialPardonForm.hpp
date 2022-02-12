/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:28:56 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 06:38:58 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		// Constructor
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &p);
		
		// Assignation operator overload
		PresidentialPardonForm& operator = (const PresidentialPardonForm &p);

		// Destructor
		virtual ~PresidentialPardonForm();

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
