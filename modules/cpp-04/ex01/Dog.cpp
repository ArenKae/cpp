/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:33 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 19:25:26 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "utils.h"

// Default constructor
Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &src) : Animal(src) // Initializes the Animal class first
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Dog& Dog::operator=(const Dog& src)
{
	if (this != &src) {
		_type = src._type; }
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

// Member function
void Dog::makeSound(void) const
{
	std::cout << BLUE << "Woof" << RESET << std::endl;
}