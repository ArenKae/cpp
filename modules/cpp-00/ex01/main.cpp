#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"
#include <iostream>

int main(void)
{
    PhoneBook MyBook;
    std::string prompt;
    int i = 0;

    std::cout << MAGENTA << "WELCOME TO MY AWESOME PHONEBOOK!" << RESET << std::endl;
    while (1)
    {
        printPrompt();
        std::getline(std::cin, prompt) && std::cout << std::endl;
        if (!std::cin || prompt.empty()) {
            std::cerr << "Input error" << std::endl;
            return (1);}
        else if (!prompt.compare("add") || !prompt.compare("ADD")) {
            if (i > 7)
                i = 0;
            MyBook.ft_add(i), i++;}
        else if (!prompt.compare("search") || !prompt.compare("SEARCH"))
            MyBook.ft_search();
        else if (!prompt.compare("exit") || !prompt.compare("EXIT")) {
            std::cout << GREEN << ">>> Bye!" << RESET << std::endl;
            return 0;}
        else
            printError("Please enter a valid command.");
    }
    return 0;
}