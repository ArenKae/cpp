/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:38 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 06:01:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void)
{
    //std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook destructor called." << std::endl;
}

void    PhoneBook::ft_add(int *i)
{
	std::cout << std::endl << "---------------------------------------------" << std::endl;
    std::cout << YELLOW << "[New contact]" << std::endl;
    std::cout << "Please enter contact informations :" << RESET << std::endl;
    PhoneBook::MyContacts[*i].add_infos(i);
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "index =" << MyContacts[*i].index << std::endl;
}

int ft_stoi(std::string input, int *num)
{
	std::stringstream ss(input);
    ss >> *num;
	if (ss.fail()) {
		if (input == "")
			print_error("Invalid input.", NONEWLINE);
		else
			print_error("Invalid input.", NEWLINE);
		return 1;}
	else if (*num < 1 || *num > 8) {
		print_error("Index must be between 1 and 8.", NEWLINE);
		return 1;}
	return 0;
}

void    PhoneBook::ft_search()
{
	int i = 0;
	std::string input;

	std::cout << std::endl << YELLOW << "[My contacts]" << RESET << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (MyContacts[i].index > 0 && i < 8) {
		PhoneBook::MyContacts[i].print_contact_list(); 
		i++; }
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << std::endl << YELLOW << "Which contact do you want to display ?" << RESET << "\n" << std::endl;
	if (!std::getline(std::cin, input)) {
		print_error("Invalid input.", NONEWLINE);
		return ;}
	else {
		int index;
		if (!ft_stoi(input, &index))
			PhoneBook::MyContacts[index - 1].display_contact_infos(index);
	}
}