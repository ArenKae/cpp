/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:09:17 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 08:40:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Default constructor
Animal::Animal(void)
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
		type = src.type; }
	return *this;
}

// Destructor
Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}