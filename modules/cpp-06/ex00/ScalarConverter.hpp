/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:12:29 by acosi             #+#    #+#             */
/*   Updated: 2024/09/26 01:44:51 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		// Static member function belongs to the class rather than the object (instance)
		// As a result, they have no this pointer, and can't 
		static void convert(std::string str);

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