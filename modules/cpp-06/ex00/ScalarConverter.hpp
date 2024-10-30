/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:12:29 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 21:50:53 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>	// atof() isinf() isnan()
#include <climits>	// INT_MIN and INT_MAX
#include <iomanip>	// std::steprecision()

class ScalarConverter
{
	public:
		/*	A static member functions belongs to the class rather than the object (instance).
			They don't need the class to be instanciated. They have no this-> pointer, 
			and can only access other static members of the class. */
		static void convert(const std::string &str);

	private:
		// Default constructor #OrthodoxCanoncialForm
		ScalarConverter(void);

		// Copy constructor #OrthodoxCanoncialForm
		ScalarConverter(const ScalarConverter &src);

		// Destructor #OrthodoxCanoncialForm
		~ScalarConverter();

		// Assignment Operator #OrthodoxCanoncialForm
		ScalarConverter& operator=(const ScalarConverter &src);
};

#endif