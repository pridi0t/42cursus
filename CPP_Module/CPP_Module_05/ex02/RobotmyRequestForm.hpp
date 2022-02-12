/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:28:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 06:35:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotMyRequestForm : public Form {
	public:
		// Constructor
		RobotMyRequestForm();
		RobotMyRequestForm(std::string name);
		RobotMyRequestForm(const RobotMyRequestForm &r);
		
		// Assignation operator overload
		RobotMyRequestForm& operator = (const RobotMyRequestForm &r);

		// Destructor
		virtual ~RobotMyRequestForm();

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
