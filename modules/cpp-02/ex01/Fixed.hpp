/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:05 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 16:12:26 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &src);	// Copy constructor
	~Fixed(void);
	
	Fixed& operator=(const Fixed &rhs);	// Copy assignment operator overload
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	
private:
	/*  "fpValue" (fixed point value) represents all the digits composing the actual number.
		The position of the decimal point is implicitely given by the fbit value. */
	int _fpValue;
	
	/* "fbits" (fractionnal bits) represents the number of bits allocated to the fractional part.
		Here, we chose to make it constant with a value of 8, but we could change it to adjust the 
		precision of the fractional part. */
	const static int _fbits = 8;
};

/*	Stream redirection (insertion) operator overload :
	Allows for a user-friendly way to directly print the value of a Fixed instance as a float.
	A member function of a class expects the left operand (the object it is called on) to be of the 
	same class type. However, in the context of streams, the left operand of "<<" is expected to be
	an object of type std::ostream. want to keep it that way in order to use it with  std::cout
	and chain redirect. This is why this function can not be a member of the class. */
std::ostream& operator<<(std::ostream &output, Fixed const &rhs); 

#endif