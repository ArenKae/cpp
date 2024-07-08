/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:30 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 11:13:04 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.h"

int main(void)
{
	PhoneBook MyBook;
	std::string input;
	int i = 0;

	std::cout << MAGENTA << "WELCOME TO MY AWESOME PHONEBOOK!" << RESET << std::endl;
	while (1)
	{
		print_prompt();
		if (!std::getline(std::cin, input))
			return 1;   // Ctrl+D
		else if (input.empty())
			print_error("Empty input.", NONEWLINE);
		else if (!input.compare("ADD")) {
			if (i > 7)
				i = 0;
			MyBook.ft_add(&i), i++;}
		else if (!input.compare("SEARCH"))
			MyBook.ft_search();
		else if (!input.compare("EXIT")) {
			std::cout << std::endl << GREEN << ">>> Bye!" << RESET << std::endl;
			return 0;}
		else
			print_error("Please enter a valid command.", NEWLINE);
	}
	return 0;
}