#include <iostream>
#include "colors.hpp"

void printError(const std::string& message)
{
	std::cout << RED << "Error: " << message << RESET << std::endl;
}

void printPrompt(void)
{
	std::cout << std::endl;
	std::cout << CYAN << "Available commands :" << std::endl;
	std::cout << GREEN << "ADD" << CYAN << " | ";
	std::cout << GREEN << "SEARCH" << CYAN << " | ";
	std::cout << GREEN << "EXIT" << RESET << std::endl;
	std::cout << std::endl;
}


void printWarning(const std::string& message)
{
	std::cout << YELLOW << "Warning: " << message << RESET << std::endl;
}


