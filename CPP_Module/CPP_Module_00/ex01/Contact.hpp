/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:24:59 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 03:26:18 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void input_string(std::string &str, std::string notice);
		void input_phone_number(std::string &str, std::string notice);
		void cut_string(std::string str);

	public:
		void init_info();
		void input_info();
		void print_info();
		void print_format_info();
};

# endif
