/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:25:25 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 08:50:15 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

#include <set>

class Span {
	private:
		std::set<int>	arr;
		unsigned int	arr_max;

		// Forbidden constructor
        Span();

	public:
        // Constructor
        Span(unsigned int n);
		Span(const Span &s);

		// Assignation operator overload
		Span& operator = (const Span &s);
		
		// Destructor
		~Span();

		// getter
		const std::set<int>	&getArr() const;
		unsigned int		getArrmax() const;

		void		addNumber(int num);
		long long	shortestSpan();
		long long	longestSpan();
		
		// Exception Class
		class InsertException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FindException : public std::exception {
			public:
				const char* what() const throw();
		};
};

// ostream overload
std::ostream& operator << (std::ostream& os, const Span &s);

# endif
