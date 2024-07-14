/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:33 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:30:23 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "utils.h"

// Default constructor
Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog constructor called." << std::endl;
}

// Copy Constructor
Dog::Dog(const Dog &src) : Animal(src), brain(new Brain(*src.brain))
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Dog& Dog::operator=(const Dog& src)
{
	if (this != &src) {
		_type = src._type;
		*brain = *src.brain; }
	return *this;
}

// Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->brain;
}

// Member function
void Dog::makeSound(void) const
{
	std::cout << BLUE "Woof" RESET << std::endl;
}