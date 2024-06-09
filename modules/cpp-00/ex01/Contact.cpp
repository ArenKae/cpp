#include "Contact.hpp"
#include "colors.hpp"
#include <iostream>

Contact::Contact(void)
{
    //std::cout << "Contact constructor called." << std::endl;
	this->index = -1; // Index starts at -1 to flag it as uninitialized.
}

Contact::~Contact(void)
{
    //std::cout << "Contact destructor called." << std::endl;
}

void    Contact::add_infos(int i)
{
	//this->index = i + 1;
	std::cout << "First name: ";
	std::getline(std::cin, this->first_name);
	if (this->first_name.empty())
    	return errorEmpty();
	std::cout << "Last name: ";
	std::getline(std::cin, this->last_name);
	if (this->last_name.empty())
		return errorEmpty();
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	if (this->nickname.empty())
		return errorEmpty();
	std::cout << "Number: ";
	std::getline(std::cin, this->number);
	if (this->number.empty())
		return errorEmpty();
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->secret);
	if (this->secret.empty())
		return errorEmpty();
	std::cout << "\n" << GREEN << ">>> New contact successfully added." << RESET << std::endl;
	this->index = i + 1;
}

void	Contact::trim_and_print(std::string)
{

}

void	Contact::print_contact_list(void)
{
	if (index > 0 && index < 7)
		std::cout << "         " << this->index << "|";
	trim_and_print(this->first_name);

	std::cout << std::endl;
	//std::cout << this->index << this->first_name << this->last_name << this->nickname << std::endl;
}