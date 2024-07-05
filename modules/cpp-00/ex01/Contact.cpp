/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:50:47 by acosi             #+#    #+#             */
/*   Updated: 2024/07/05 02:37:11 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.h"
#include <iostream>

Contact::Contact(void)
{
    //std::cout << "Contact constructor called." << std::endl;
	this->index = -1; // Index starts at -1 to flag it as uninitialized.
}

Contact::~Contact(void)
{
    //std::cout << "Contact destructor called." << std::endl;
}

void    Contact::add_infos(int *i)
{
	std::cout << "First name: ";
	std::getline(std::cin, this->first_name);
	if (this->first_name.empty())
    	return error_empty(i);
	std::cout << "Last name: ";
	std::getline(std::cin, this->last_name);
	if (this->last_name.empty())
		return error_empty(i);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	if (this->nickname.empty())
		return error_empty(i);
	std::cout << "Number: ";
	std::getline(std::cin, this->number);
	if (this->number.empty())
		return error_empty(i);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->secret);
	if (this->secret.empty())
		return error_empty(i);
	std::cout << "\n" << GREEN << ">>> New contact successfully added." << RESET << std::endl;
	this->index = *i + 1;
}

int input_length(const std::string& str)
{
    int count = 0;
    for (std::size_t i = 0; i < str.size(); ) {
        unsigned char c = str[i];
        if (c < 128) {
            // ASCII character
            i += 1;
        } else if ((c >> 5) == 0b110) {
            // Two-byte character
            i += 2;
        } else if ((c >> 4) == 0b1110) {
            // Three-byte character
            i += 3;
        } else if ((c >> 3) == 0b11110) {
            // Four-byte character
            i += 4;
        } else {
            // Invalid UTF-8, just skip this byte
            i += 1;
        }
        count++;
    }
    return count;
}

void Contact::trim_and_print(std::string info)
{
    int len = input_length(info);

    if (len > 10) {
        // Truncate the string and add a dot at the end
        int char_count = 0;
        for (std::size_t i = 0; i < info.size(); ) {
            unsigned char c = info[i];
            if (c < 128) {
                std::cout << info[i];
                i += 1;
            } else if ((c >> 5) == 0b110) {
                std::cout << info.substr(i, 2);
                i += 2;
            } else if ((c >> 4) == 0b1110) {
                std::cout << info.substr(i, 3);
                i += 3;
            } else if ((c >> 3) == 0b11110) {
                std::cout << info.substr(i, 4);
                i += 4;
            } else {
                i += 1;
            }
            char_count++;
            if (char_count == 9) {
                std::cout << ".";
                break;
            }
        }
    } else {
        int diff = 10 - len;
        while (diff > 0) {
            std::cout << " ";
            diff--;
        }
        std::cout << info;
    }
    std::cout << "|";
}

void	Contact::print_contact_list(void)
{
	if (index > 0 && index < 9)
		std::cout << "|         " << this->index << "|";
	trim_and_print(this->first_name);
	trim_and_print(this->last_name);
	trim_and_print(this->nickname);
	std::cout << std::endl;
}

void    Contact::display_contact_infos(int i)
{
    if (this->index == -1 || i <= 0) {
        print_error("This contact does not exist.", NEWLINE);
        return ;}
    std::cout << "\n" << GREEN << ">>> Displaying contact " << YELLOW << "[" << RESET << i << YELLOW << "]" ;
    std::cout << GREEN << " infos." << RESET << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "First name: " << this->first_name << std::endl;
    std::cout << "Last name: " << this->last_name << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->number << std::endl;
    std::cout << "Darkest secret: " << this->secret << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
}