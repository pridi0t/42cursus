/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:07:25 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/15 07:43:45 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALAR_HPP
# define SCALAR_HPP

#include <exception>
#include <iostream>
#include <string>
#include <climits>

class Scalar {
	private:
		std::string original_value;
		double		dvalue;
		
		// Forbidden constructors
		Scalar();
		
	public:
		// Constructor
		Scalar(std::string arg);
		Scalar(const Scalar &s);
		
		// Assignation operator overload
		Scalar& operator = (const Scalar &s);

		// Destructor
		~Scalar();

		// getter
		std::string	getOriginal() const;
		double		getDvalue() const;
		
		char	convertChar(double dvalue);
		int		convertInt(double dvalue);
		float	convertFloat(double dvalue);

		// Exception Class
		class ConstructorException : public std::exception {
			public:
				const char* what() const throw();
		};

		class ImpossibleException : public std::exception {
			public:
				const char* what() const throw();
		};

		class NonDisplayableException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// ostream overload
std::ostream& operator << (std::ostream& os, Scalar &s);

# endif
