/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:45:29 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:30:33 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "utils.h"

// Default constructor
WrongAnimal::WrongAnimal(void) : _type("Undefined wrong animal")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

// Type initialization constructor
WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

// Copy Constructor
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src) {
		_type = src._type; }
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Getter function for _type attribute
std::string WrongAnimal::getType(void) const
{
	return this->_type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << RED "*Totally not wrong animal sounds*" RESET << std::endl;
}