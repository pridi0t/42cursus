/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:01 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/10 10:00:50 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		// Constructor
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &b);
		
		// Assignation operator overload
		Bureaucrat& operator = (const Bureaucrat &b);

		// Destructor
		~Bureaucrat();

		std::string getName() const;
		int			getGrade() const;
		void		upGrade();
		void		downGrade();

		// Exception Class
		class GradeTooHighException : public std::Exception {}
		class GradeTooLowException : public std::Exception {}
};

// ostream overload


# endif
