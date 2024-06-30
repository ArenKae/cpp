/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:51:04 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 06:07:02 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <iostream>

void print_error(const std::string& message, int flag)
{
	if (flag == 0)
		std::cout << "\n";
	std::cerr << RED << "Error: " << message << RESET << std::endl;
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

void error_empty(int *i)
{
	std::cerr << RED << "Error: A contact can't have empty fields." << RESET << std::endl;
	*i -= 1; // In case of error, prevents iterator i from increasing in the main()
	return ;
}