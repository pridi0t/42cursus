/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:01 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 03:03:36 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	name;
		int					grade;

	public:
		// Constructor
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		
		// Assignation operator overload
		Bureaucrat& operator = (const Bureaucrat &b);

		// Destructor
		~Bureaucrat();

		std::string getName() const;
		int			getGrade() const;
		void		upGrade();
		void		downGrade();
		void		signForm(Form &f);

		// Exception Class
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// ostream overload
std::ostream& operator << (std::ostream& os, const Bureaucrat &b);

# endif
