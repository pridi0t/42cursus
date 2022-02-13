/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotmyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:28:20 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 11:42:50 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ROBOTMYREQUESTFORM_HPP
# define ROBOTMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "Form.hpp"

class RobotmyRequestForm : public Form {
	private:
		// Forbidden Constructor
		RobotmyRequestForm();

	public:
		// Constructor
		RobotmyRequestForm(std::string target);
		RobotmyRequestForm(const RobotmyRequestForm &r);
		
		// Assignation operator overload
		RobotmyRequestForm& operator = (const RobotmyRequestForm &r);

		// Destructor
		virtual ~RobotmyRequestForm();

		// Override
		void	execute(Bureaucrat const & excutor) const;
};

# endif
