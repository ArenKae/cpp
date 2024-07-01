/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:05 by acosi             #+#    #+#             */
/*   Updated: 2024/07/01 01:42:45 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

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
	int getFpValue(void) const;
	
private:
	int _fpValue;
	const static int _fbits = 8;
};

#endif