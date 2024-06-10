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
	std::cout << std::endl << "--------------------------------------------" << std::endl;
    std::cout << YELLOW << "[New contact]" << std::endl;
    std::cout << "Please enter contact informations :" << RESET << std::endl;
    PhoneBook::MyContacts[i].add_infos(i);
	std::cout << "--------------------------------------------" << std::endl;
}

#include <cstdlib>
#include <cstring>
#include <sstream>

bool isNumber(const char* str) {
    if (!str || std::strlen(str) == 0) // Check if string is null or empty
        return false;

    // Check each character to see if it's a digit
    for (const char* c = str; *c != '\0'; ++c) {
        if (!std::isdigit(*c))
            return false;
    }

    return true;
}

int ft_stoi(std::string input, int *number)
{
    if (isNumber(input.c_str())) {
        *number = std::atoi(input.c_str());
		return 0;}
	else {
		printError("Index must be a numerical value.");
		return 1;}
}

void    PhoneBook::ft_search()
{
	int i = 0;
	std::string input;

	std::cout << std::endl << YELLOW << "[My contacts]" << RESET << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
    std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (MyContacts[i].index > 0 && i < 8) {
		PhoneBook::MyContacts[i].print_contact_list(); 
		i++; }
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << std::endl << YELLOW << "Which contact do you want to display ?" << RESET << "\n" << std::endl;
	if (!std::getline(std::cin, input)) {
		printError("Input Error.");
		return ;}
	else {
		int index;
		if (!ft_stoi(input, &index))
			PhoneBook::MyContacts[index - 1].display_contact_infos(index);
	}

}