/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:38:42 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/13 02:59:59 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <iomanip>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	name;
		bool				signature;
		const int			required_grade;
		const int			exe_grade;

	public:
		// Constructor
		Form();
		Form(std::string name, int rgrade, int egrade);
		Form(const Form &f);
		
		// Assignation operator overload
		Form& operator = (const Form &f);

		// Destructor
		~Form();

		std::string getName() const;
		int			getSignature() const;
		int			getRequiredGrade() const;
		int			getExeGrade() const;
		void		beSigned(Bureaucrat &b);

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
std::ostream& operator << (std::ostream& os, const Form &f);

# endif
