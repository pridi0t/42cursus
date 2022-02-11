/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:38:42 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/12 04:03:19 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>

class Form {
	private:
		const std::string	name;
		bool				signature;
		const int			required_grade;
		const int			exe_grade;

	public:
		// Constructor
		Form();
		Form(const Form &f);
		
		// Assignation operator overload
		Form& operator = (const Form &f);

		// Destructor
		~Form();

		std::string getName() const;
		int			getSignature() const;
		void		getRequiredGrade() const;
		void		getExeGrade() const;
		void		beSigned();
		void		signForm();

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
