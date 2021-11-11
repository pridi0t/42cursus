/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojang <hyojang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:10:03 by hyojang           #+#    #+#             */
/*   Updated: 2021/11/12 05:08:07 by hyojang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
	private:
		int index;
		int cnt;
		Contact pbook[8];
		void print_table();
		int check_invalid(std::string str);
		int	atoi_for_phonebook(std::string str);
	
	public:
		PhoneBook();
		void add();
		void search();
};

# endif
