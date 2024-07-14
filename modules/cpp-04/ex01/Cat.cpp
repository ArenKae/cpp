/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:24 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:30:16 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "utils.h"

// Default constructor
Cat::Cat(void) : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat constructor called." << std::endl;
}

// Copy Constructor
Cat::Cat(const Cat &src) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Cat& Cat::operator=(const Cat& src)
{
	if (this != &src) {
		_type = src._type;
		*brain = *src.brain; }
	return *this;
}

// Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->brain;
}

// Member function
void Cat::makeSound(void) const
{
	std::cout << GREEN "Meow" RESET << std::endl;
}