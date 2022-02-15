/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 00:07:25 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/15 01:37:39 by marvin           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <string>

class Scalar {
	private:
		std::string value;

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

		char	convertChar(std::string str);
		int		convertInt(std::string str);
		float	convertFloat(std::string str);
		double	convertDouble(std::string str);

		// Exception Class
		class ImpossibleException : public std::exception {
			public:
				const char* what() const throw();
		};

		class ConvertCharException : public std::exception {
			public:
				const char* what() const throw();
		};

		class ConvertIntException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// ostream overload
std::ostream& operator << (std::ostream& os, const Scalar &s);

# endif
