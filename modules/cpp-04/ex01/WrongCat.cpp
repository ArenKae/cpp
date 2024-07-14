/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:45:36 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:31:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "utils.h"

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal("Wrong cat")
{
	std::cout << "WrongCat constructor called." << std::endl;
}

// Copy Constructor
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src) // Initializes the Animal class first
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if (this != &src) {
		_type = src._type; }
	return *this;
}

// Destructor
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

// Member function
void WrongCat::makeSound(void) const
{
	std::cout << RED "Meow! Feed me or I'll murder your entire family (•ㅅ•)" RESET << std::endl;
}