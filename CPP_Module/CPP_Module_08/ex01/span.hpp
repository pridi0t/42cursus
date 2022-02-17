/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 00:25:25 by hyojang           #+#    #+#             */
/*   Updated: 2022/02/18 00:32:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

class Span {
	private:
	public:
        // Constructor
        Span();
		Span(const Span &s);

		// Assignation operator overload
		Span& operator = (const Span &s);
		
		// Destructor
		~Span();


}

# endif
