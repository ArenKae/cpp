/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:10 by acosi             #+#    #+#             */
/*   Updated: 2024/07/04 15:55:21 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*  Constant integer constructor
	Converts an int to a fixed-point number. */
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	/*  Bit-shifting the num value by 8 bits (the chosen value of _fbits) so that the
		8 lower bits (i.e the fractional part) become all zeros. This operation is
		equivalent to multiplying the integer by 2^8 = 256. */
	_fpValue = num << _fbits;
}

/*  Constant floating-point number constructor
	Converts a float to a fixed-point number. */
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	/*  Similarly, we multiply the value "num" by 256 (1 shifted by 8 bits) to shift the
		decimal part of the number into the integer part. As this result is a float itself,
		we must round it to the nearest integer with roundf() to make it an int. Without this
		the decimal part of the result would be truncated, resulting in a precision loss. */
	_fpValue = roundf(num * (1 << _fbits));
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

/* Getter function for private attribute fpValue */
int Fixed::getFpValue(void) const
{
	return this->_fpValue;
}

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

/*	Converts the fixed-point number value of the current instance to an int.
	To make the conversion, we simply do the reverse operation performed by the int constructor. */
int Fixed::toInt(void) const
{
	return (this->_fpValue >> this->_fbits);
}

/*	Converts the fixed-point number value of the current instance to a float.
	To make the conversion, we simply do the reverse operation performed by the float constructor. */
float Fixed::toFloat(void) const
{
	return ((float)(this->_fpValue) / (float)(1 << _fbits));
}

/* Copy assignement operator overload */
Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpValue = rhs.getFpValue();
	return *this;
}

/*	Stream redirection (insertion) operator overload
	Allows for a user-friendly way to directly print the value of a Fixed instance as a float.
	Since the ostream class is not part of the Fixed class, we can't change the left operand  */
std::ostream& operator<<(std::ostream &output, Fixed const &rhs)
{
	output << rhs.toFloat();
	return output;
}