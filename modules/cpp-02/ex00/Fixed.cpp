/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:10 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 15:14:16 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* Destructor */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* Copy assignement operator overload */
Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpValue = rhs.getRawBits();
	return *this;
}

/* Getter function for private attribute fpValue */
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fpValue = raw;
}