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
    std::cout << YELLOW << "[New contact]" << std::endl;
    std::cout << "Please enter contact informations :" << RESET << std::endl;
    PhoneBook::MyContacts[i].add_infos();
    //std::cout << "i = " << i << std::endl;
}

void    PhoneBook::ft_search(void)
{
    std::cout << "Searching..." << std::endl;
}