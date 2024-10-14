/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:45:04 by acosi             #+#    #+#             */
/*   Updated: 2024/10/14 22:57:56 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"

static void print_str(std::string str)
{
	std::cout << GREEN << str << RESET << std::endl;
}

// Test if the parameter is a char type.
static bool    is_char(std::string str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	else
		return false;
}

// Test if the parameter is an integer type.
static bool    is_integer(std::string str)
{
    int    nb;
    std::istringstream    iss(str);	// Creates a string stream object (iss) using the string str.
    iss >> nb;	// The >> operator attempts to convert iss into the type of nb (int).
	
	// Returns true if there are no extra characters left in the stream and if no conversion errors occur.
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a double type.
static bool    is_double(std::string str)
{
    double    nb;
    std::istringstream    iss(str);
    iss >> nb;
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a float type.
static bool    is_float(std::string str)
{
    if (str[str.size() - 1] == 'f') // Checks if str ends with an 'f'
    {
        std::string trimmed = str.substr(0, str.size() - 1); // Removes the final 'f'
        float    nb;
        std::istringstream    iss(trimmed);
        iss >> nb;	// Attempts to convert the trimmed string into a float
        return (iss.eof() && !iss.fail());
    }
    return (false);
}

void    ScalarConverter::convert(std::string str)
{
    int    type = -1;

    bool (*fuctions[])(std::string str) = {&is_char, &is_integer, &is_double, &is_float};
    for (int i = 0; i < 4; i++)
    {
        if (fuctions[i](str))
        {
            type = i;
            break ;
        }
    }
	print_str(str);
	switch (type)
	{
		case 0:
			print_str("char");
			break;
		case 1:
			print_str("integer");
			break;
		case 2:
			print_str("double");
			break;
		case 3:
			print_str("float");
			break;
		default:
			print_str("unknown type");
			break;
	}
}