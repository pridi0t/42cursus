/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:24:27 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/31 00:57:38 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {
	private:
		std::string	name;
		std::string	weapon;

	public:
		HumanA(std::string name, Weapon weapon);
		void			setType(Weapon weapon);
		void			attack();
}

# endif
