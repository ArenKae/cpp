/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:05 by acosi             #+#    #+#             */
/*   Updated: 2024/07/01 01:27:29 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const & src);	// Copy constructor
	~Fixed(void);
	
	Fixed& operator=(Fixed const & rhs);	// Copy assignment operator overload
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int getFpValue(void) const;
	
private:
	int fpValue;
	const static int fbits = 8;
};

#endif