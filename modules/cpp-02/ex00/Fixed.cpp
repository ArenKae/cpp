/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:10 by acosi             #+#    #+#             */
/*   Updated: 2024/07/01 01:34:18 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)	// Default constructor
{
	std::cout << "Default constructor called" << std::endl;
	this->fpValue = 0;
}

Fixed::Fixed(Fixed const & src)		// Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)		// Destructor
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getFpValue(void) const	// Getter for private attribute fpValue 
{
	return this->fpValue;
}

Fixed& Fixed::operator=(Fixed const & rhs)	// Copy assignement operator overload
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->fpValue = rhs.getFpValue();
	return *this;
}

int Fixed::getRawBits(void) const
{
	
}

void Fixed::setRawBits(int const raw)
{
	
}