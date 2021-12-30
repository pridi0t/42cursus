/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 00:36:47 by hyojang           #+#    #+#             */
/*   Updated: 2021/12/31 00:54:54 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string type);
		const std::string	&getType();
		void				setType(std::string type);
}

# endif
