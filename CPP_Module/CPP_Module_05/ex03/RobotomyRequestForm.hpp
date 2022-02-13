/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:28:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 16:01:36 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotomyRequestForm : public Form {
	private:
		// Forbidden Constructor
		RobotomyRequestForm();

	public:
		// Constructor
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &r);
		
		// Assignation operator overload
		RobotomyRequestForm& operator = (const RobotomyRequestForm &r);

		// Static member function
		static Form *create(std::string &target);
		
		// Destructor
		virtual ~RobotomyRequestForm();

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
