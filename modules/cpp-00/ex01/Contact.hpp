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
		int index;
		void add_infos(void);
};

#endif