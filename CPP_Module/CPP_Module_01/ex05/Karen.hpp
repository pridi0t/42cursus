/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 20:01:44 by hyojang           #+#    #+#             */
/*   Updated: 2022/01/02 02:11:37 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef KAREN_HPP
# define KAREN_HPP

class Karen {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);
};

# endif
