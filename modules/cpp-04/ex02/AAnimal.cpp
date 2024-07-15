/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:09:17 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:34:14 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "utils.h"

// Default constructor
Animal::Animal(void) : _type("Undefined animal")
{
	std::cout << "Animal constructor called." << std::endl;
}

// Type initialization constructor
Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal constructor called." << std::endl;
}

// Copy Constructor
Animal::Animal(const Animal &src)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Animal& Animal::operator=(const Animal& src)
{
	if (this != &src) {
		_type = src._type; }
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}