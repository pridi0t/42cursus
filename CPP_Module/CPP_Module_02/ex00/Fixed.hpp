/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:11:42 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/19 19:45:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fbit = 8;

	public:
		Fixed();
		Fixed(const Fixed& fix);
		Fixed& operator=(const Fixed &fix);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

# endif
