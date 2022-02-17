/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:25:25 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 03:12:28 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

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

		void	addNumber(int num);
		//shortestSpan();
		//longestSpan();
		
		// Exception Class
		class InsetException : public std::exception {
			public:
				const char* what() const throw();
		};

		class FindException : public std::exception {
			public:
				const char* what() const throw();
		};
}

# endif
