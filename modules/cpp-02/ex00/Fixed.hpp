/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:05 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 15:14:24 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed &src);	// Copy constructor
	~Fixed(void);
	
	Fixed& operator=(const Fixed &rhs);	// Copy assignment operator overload
	int getRawBits(void) const;
	void setRawBits(int const raw);
	
private:
	/*  "fpValue" (fixed point value) represents all the digits composing the actual number.
		The position of the decimal point is implicitely given by the fbit value. */
	int _fpValue;
	
	/* "fbits" (fractionnal bits) represents the number of bits allocated to the fractional part.
		Here, we chose to make it constant with a value of 8. */
	const static int _fbits = 8;
};

#endif