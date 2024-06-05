#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
    //std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook destructor called." << std::endl;
}

void    PhoneBook::ft_add(int i)
{
	std::cout << "-----------------------------------------" << std::endl;
    std::cout << YELLOW << "[New contact]" << std::endl;
    std::cout << "Please enter contact informations :" << RESET << std::endl;
    PhoneBook::MyContacts[i].add_infos(i);
	std::cout << "-----------------------------------------" << std::endl;
    //std::cout << "i = " << i << std::endl;
}

void    PhoneBook::ft_search()
{
	int i = 0;

	std::cout << "-----------------------------------------" << std::endl;
    std::cout << YELLOW << "[My contact]" << RESET << std::endl;
	while (MyContacts[i].index > 0 && i < 7) {
		PhoneBook::MyContacts[i].print_contact_list(); 
		i++; }
	std::cout << "-----------------------------------------" << std::endl;
}