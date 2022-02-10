/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:44:01 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/10 15:10:10 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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

		// Exception Class
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const;
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const;
		};
};

// ostream overload
std::ostream& operator << (std::ostream& os, const Bureaucrat &b);

# endif
