/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:07:03 by acosi             #+#    #+#             */
/*   Updated: 2024/07/05 02:26:50 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.h"
#include "utils.h"

int	print_error(const char* filename, int flag)
{
	if (flag == OPEN) {
		std::cerr <<  RED << "Error while opening file "  << RESET << "\""
		YELLOW << filename << RESET << "\"" << std::endl; }
	else if (flag == CREATE) {
		std::cerr <<  RED << "Error while creating file "  << RESET << "\""
		YELLOW << filename << RESET << "\"" << std::endl; }
	else if (flag == TOO_MANY_ARGS) {
		std::cerr << RED << "Error: too many arguments" << RESET << std::endl;
		std::cout << YELLOW << "Usage: " RESET << "./replace " << "<" << BLUE 
		<< "filename" << RESET << "> " << "<" BLUE << "string_to_match" << RESET 
		<< "> " << "<" << BLUE << "replacement_string" << RESET << ">" << std::endl;}
	else if (flag == TOO_FEW_ARGS) {
		std::cerr << RED << "Error: too few arguments" << RESET << std::endl;
		std::cout << YELLOW << "Usage: " RESET << "./replace " << "<" << BLUE 
		<< "filename" << RESET << "> " << "<" BLUE << "string_to_match" << RESET 
		<< "> " << "<" << BLUE << "replacement_string" << RESET << ">" << std::endl;}
	return (EXIT_FAILURE);
}

int main(int ac, char** av)
{
    if (ac > 4)
		return print_error(NULL, TOO_MANY_ARGS);
	else if (ac < 4)
		return print_error(NULL, TOO_FEW_ARGS);
		
    if (!replace(av))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

