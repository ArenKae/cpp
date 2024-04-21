#include "Contact.hpp"
#include "colors.hpp"
#include <iostream>

void    Contact::add_infos(void)
{
    std::cout << "First name : ";
    std::cin >> this->first_name;
    if (this->first_name.empty())
        std::cerr << "Input error." << std::endl;
    std::cout << "Last name : ";
    std::cin >> this->last_name;
    if (this->last_name.empty())
        std::cerr << "Input error." << std::endl;
    std::cout << GREEN << ">>> New contact successfully added." << RESET << std::endl << std::endl;
}