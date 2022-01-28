/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:11:42 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/28 12:03:01 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fbit = 8;

	public:
		// Constructor
		Fixed();
		Fixed(const int ivalue);
		Fixed(const float fvalue);
		Fixed(const Fixed& fix);

		// Assignation operator overload
		Fixed& operator = (const Fixed &fix);

		// Comparision operators
		bool	operator > (const Fixed &fix);
		bool	operator < (const Fixed &fix);
		bool	operator >= (const Fixed &fix);
		bool	operator <= (const Fixed &fix);
		bool	operator == (const Fixed &fix);
		bool	operator != (const Fixed &fix);

		// Arithmetic operators
		Fixed	operator + (const Fixed &fix);
		Fixed	operator - (const Fixed &fix);
		Fixed	operator * (const Fixed &fix);
		Fixed	operator / (const Fixed &fix);

		// Increment/Decrement operators
		Fixed&	operator ++ ();
		Fixed	operator ++ (int);
		Fixed&	operator -- ();
		Fixed	operator -- (int);

		// Destructor
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		// publit static member functions overloads
		// min??
		// max
};

std::ostream& operator<<(std::ostream& os, const Fixed &fix);

# endif
