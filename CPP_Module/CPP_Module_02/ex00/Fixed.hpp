/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:11:42 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/17 19:14:30 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int integer_parts;
		int fractional_parts;

	public:
		Fixed();
		Fixed(const Fixed& fix);	// copy constructor
		Fixed  &Fixed::operator = (const Fixed &fix);
		~Fixed();

		int		getRawBits(void);
		void	setRawbits(int const raw);
};

# endif
