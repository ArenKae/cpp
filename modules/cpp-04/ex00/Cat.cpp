/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:24 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:31:56 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "utils.h"

// Default constructor
Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat constructor called." << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &src) : Animal(src) // Initializes the Animal class first
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Cat& Cat::operator=(const Cat& src)
{
	if (this != &src) {
		_type = src._type; }
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

// Member function
void Cat::makeSound(void) const
{
	std::cout << GREEN "Meow" RESET << std::endl;
}