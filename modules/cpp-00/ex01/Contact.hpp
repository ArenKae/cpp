#ifndef CONTACT_H
#define CONTACT_H

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
		void add_infos(int i);
		void print_contact_list(void);
		void trim_and_print(std::string);
		void trim(std::string);
		void display_contact_infos(int);
};

#endif