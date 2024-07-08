/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:10 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 16:16:52 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Default constructor */
Fixed::Fixed(void) : _fpValue(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

/*  Constant integer constructor
	Converts an int to a fixed-point number. */
Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	/*  Bit-shifting the num value by 8 bits (the chosen value of _fbits) so that the
		8 lower bits (i.e the fractional part) become all zeros. This operation is
		equivalent to multiplying the integer by 2^8 = 256. */
	_fpValue = num << _fbits;
}

/*  Constant floating-point number constructor
	Converts a float to a fixed-point number. */
Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	/*  Similarly, we multiply the value "num" by 256 (1 shifted by 8 bits) to shift the
		decimal part of the number into the integer part. As this result is a float itself,
		we must round it to the nearest integer with roundf() to make it an int. Without this
		the decimal part of the result would be truncated, resulting in a precision loss. */
	_fpValue = roundf(num * (1 << _fbits));
}

/* Copy constructor */
Fixed::Fixed(const Fixed &src)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/* Destructor */
Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

/* Getter function for private attribute fpValue */
int Fixed::getFpValue(void) const
{
	return this->_fpValue;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return this->_fpValue;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fpValue = rhs.getFpValue();
	return *this;
}

/*	Stream redirection (insertion) operator overload
	Allows for a user-friendly way to directly print the value of a Fixed instance as a float.
	A member function of a class expects the left operand (the object it is called on) to be of the 
	same class type. However, in the context of streams, the left operand of "<<" is expected to be
	an object of type std::ostream. want to keep it that way in order to use it with  std::cout
	and chain redirect. This is why this function can not be a member of the class. */
std::ostream& operator<<(std::ostream &output, Fixed const &rhs)
{
	output << rhs.toFloat();
	return output;
}

/*	Arithmetic operators overload :
	We return a new "Fixed" instance every time so that its constructor will 
	convert the result of the operation (a float) back to the fixed-point representation. */

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed (this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed (this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed (this->toFloat() / rhs.toFloat()));
}

// Comparison operators overload :

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_fpValue < rhs._fpValue);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_fpValue > rhs._fpValue);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_fpValue <= rhs._fpValue);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_fpValue >= rhs._fpValue);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_fpValue == rhs._fpValue);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_fpValue != rhs._fpValue);
}

//	Increment/decrement operators overload :

/*	Pre-increment operator overload :
	The value is incremented first and then returned. */
Fixed	&Fixed::operator++(void)
{
	this->_fpValue++;
	return (*this);
}

/*	Post-increment operaotr overload :
	The value is returned unchanged for use in an expression, and then incremented. */
Fixed   Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_fpValue++;
	return (temp);
}

//	Pre-decrement operator overload :
Fixed	&Fixed::operator--(void)
{
	this->_fpValue--;
	return (*this);
}

//	Post-decrement operaotr overload :
Fixed   Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_fpValue--;
	return (temp);
}

//	Min/max overloaded member functions :

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
