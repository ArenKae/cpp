#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"
#include <iostream>

int main(void)
{
    PhoneBook MyBook;
    std::string input;
    int i = 0;

    std::cout << MAGENTA << "WELCOME TO MY AWESOME PHONEBOOK!" << RESET << std::endl;
    while (1)
    {
        printPrompt();
        if (!std::getline(std::cin, input))
            return 1;
        else if (input.empty())
            printError("Empty input.");
        else if (!input.compare("add") || !input.compare("ADD")) {
            if (i > 7)
                i = 0;
            MyBook.ft_add(i), i++;}
        else if (!input.compare("search") || !input.compare("SEARCH"))
            MyBook.ft_search();
        else if (!input.compare("exit") || !input.compare("EXIT")) {
            std::cout << GREEN << ">>> Bye!" << RESET << std::endl;
            return 0;}
        else
            printError("Please enter a valid command.");
    }
    return 0;
}