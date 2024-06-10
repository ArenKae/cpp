#include "utils.hpp"
#include <iostream>

void print_error(const std::string& message, int flag)
{
	if (flag == 0)
		std::cout << "\n";
	std::cout << RED << "Error: " << message << RESET << std::endl;
}

void print_prompt(void)
{
	std::cout << std::endl;
	std::cout << CYAN << "Available commands :" << std::endl;
	std::cout << GREEN << "ADD" << CYAN << " | ";
	std::cout << GREEN << "SEARCH" << CYAN << " | ";
	std::cout << GREEN << "EXIT" << RESET << std::endl;
	std::cout << std::endl;
}

void error_empty(void)
{
	std::cerr << RED << "Error: A contact can't have empty fields." << RESET << std::endl;
	return ;
}