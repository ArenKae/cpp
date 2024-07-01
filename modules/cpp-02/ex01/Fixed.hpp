/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:05 by acosi             #+#    #+#             */
/*   Updated: 2024/07/01 05:12:50 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

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
	int getFpValue(void) const;
    float toFloat(void) const;
    int toInt(void) const;
	
private:
    /*  "fpValue" (fixed point value) represents all the digits composing the actual number.
        The position of the decimal point is implicitely given by the fbit value. */
	int _fpValue;
    
    /* "fbits" (fractionnal bits) represents the number of bits allocated to the fractional part.
        Here, we chose to make it constant with a value of 8, but we could change it to adjust the precision of the fractional part. */
	const static int _fbits = 8;
};

std::ostream& operator<<(std::ostream &output, Fixed const &rhs); 

#endif