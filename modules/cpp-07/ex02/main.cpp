/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:59:35 by acosi             #+#    #+#             */
/*   Updated: 2024/11/15 17:41:39 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "utils.h"

int main(void)
{
	try
	{
		std::cout << MAGENTA "[EMPTY ARRAY TEST]" RESET << std::endl;
		// Empty array test with default constructor
        Array<int> emptyArray;
        emptyArray.printSize("emptyArray");
		std::cout << "*Nothing but chickens here*" << emptyArray << std::endl;

        std::cout << MAGENTA "\n[INT ARRAY TEST]" RESET << std::endl;
		// Int array test with size constructor
        Array<int> intArray(5);
		intArray.printSize("intArray");
		std::cout << CYAN "intArray" RESET " inital content: " << intArray << RESET << std::endl;

		// Copy constructor
		Array<int> copyArray(intArray);
		std::cout << YELLOW "-> Making a copy of intArray into copyArray..." RESET << std::endl;
		copyArray.printSize("copyArray");
		std::cout << CYAN "copyArray" RESET " inital content: " << copyArray << std::endl;

		// Modifying intArray content and check that copyArray is unchanged
		std::cout << YELLOW "-> Modifying intArray content..." RESET << std::endl;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			intArray[i] = i;
		std::cout << CYAN "intArray" RESET " modified content: " << intArray << RESET << std::endl;
		std::cout << CYAN "copyArray" RESET " content: " << copyArray << std::endl;

		// Out of bound access test
		std::cout << YELLOW "-> Attempting to access out of bound element..." RESET << std::endl;
		std::cout << intArray[5] << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
	
	try
	{
        std::cout << MAGENTA "\n[CHAR ARRAY TEST]" RESET << std::endl;
		// Char array test with size constructor
        Array<char> charArray(7);
		charArray.printSize("charArray");
		
		// Filling charArray with alphabet
		std::cout << YELLOW "-> Filling charArray content..." RESET << std::endl;
		for (unsigned int i = 0; i < charArray.size(); ++i)
			charArray[i] = i + 97;
		std::cout << CYAN "charArray" RESET " initial content: " << charArray << RESET << std::endl;

		// Copy constructor
		Array<char> copyArray(charArray);
		std::cout << YELLOW "-> Making a copy of charArray into copyArray..." RESET << std::endl;
		copyArray.printSize("copyArray");
		std::cout << CYAN "copyArray" RESET " inital content: " << copyArray << std::endl;

		std::cout << YELLOW "-> Modifying charArray content..." RESET << std::endl;
		charArray[5] = '4';
		charArray[6] = '2';
		std::cout << CYAN "charArray" RESET " modified content: " << charArray << RESET << std::endl;
		std::cout << CYAN "copyArray" RESET " content: " << copyArray << std::endl;

		// Out of bound access test
		std::cout << YELLOW "-> Attempting to access out of bound element..." RESET << std::endl;
		std::cout << charArray[10] << std::endl;
	}
	catch (const std::out_of_range &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	return 0;
}