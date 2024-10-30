/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 03:30:55 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 16:18:49 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include "utils.h"
#include <iostream>

int main()
{
	Data myData = {.id = 42, .info = "Test"};

	// Serialize the pointer to data :
	uintptr_t raw = Serializer::serialize(&myData);

	// Deserialize it back to a Data pointer :
	Data *newData = Serializer::deserialize(raw);

	// Test if the original and deserialized pointer are the same :
	std::cout << BLUE "Original Data pointer = " << &myData << RESET << std::endl; // Adress in hexadecimal
	std::cout << YELLOW "uintptr_t = " << raw << RESET << std::endl; // Adress but treated as an unsigned int
	std::cout << BLUE "New Data pointer = " << newData << RESET << std::endl;
	std::cout << "NewData ID: " << newData->id << ", NewData Info: " << newData->info << std::endl;

	if (newData == &myData)
		std::cout << GREEN "\n-> Serialization / deserialization successful!" RESET << std::endl;
	else
		std::cout << RED "\n-> Serialization / deserialization failed!" RESET << std::endl;

	// Test that the class is not instanciable :
	// Serializer obj;

	return 0;
}