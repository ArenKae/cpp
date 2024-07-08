/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:51:17 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 11:24:14 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		Contact(void);
		~Contact(void);
		int index;
		void add_infos(int *i);
		void print_contact_list(void);
		void trim_and_print(std::string);
		void trim(std::string);
		void display_contact_infos(int);
};

#endif