/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:45:04 by acosi             #+#    #+#             */
/*   Updated: 2024/10/15 05:01:06 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"

// Test if the parameter is a char type.
static bool    is_char(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	else
		return false;
}

// Test if the parameter is an integer type.
static bool    is_integer(const std::string &str)
{
    int    nb;
    std::istringstream    iss(str);	// Creates a string stream object (iss) using the string str.
    iss >> nb;	// The >> operator attempts to convert iss into the type of nb (int).
	
	// Returns true if there are no extra characters left in the stream and if no conversion errors occur.
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a double type.
static bool    is_double(const std::string &str)
{
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return true;
    double    nb;
    std::istringstream    iss(str);
    iss >> nb;
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a float type.
static bool    is_float(const std::string &str)
{
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
		return true;
    else if (str[str.size() - 1] == 'f') // Checks if str ends with an 'f'
    {
        std::string trimmed = str.substr(0, str.size() - 1); // Removes the final 'f'
        float    nb;
        std::istringstream    iss(trimmed);
        iss >> nb;	// Attempts to convert the trimmed string into a float
        return (iss.eof() && !iss.fail());
    }
    return (false);
}

static std::string findType(const std::string &str)
{
	int    type = -1;

    bool (*fuctions[])(const std::string &str) = {&is_char, &is_integer, &is_float, &is_double,};
    for (int i = 0; i < 4; i++)
    {
        if (fuctions[i](str))
        {
            type = i;
            break ;
        }
    }
	switch (type)
	{
		case 0:
			return "char";
			break;
		case 1:
			return "integer";
			break;
		case 2:
			return "float";
			break;
		case 3:
			return "double";
			break;
		default:
			return "unknown type";
			break;
	}
}

void toChar(const double &value, const std::string &type)
{
	char convertedChar = static_cast<char>(value);

	if (type == "char" && std::isprint(value))
        std::cout << "char : \'" << convertedChar << "\'" << std::endl;

	else if ((type == "int" || type == "double" || type == "float") && value >= 32 && value <= 126)
        std::cout << "char : \'" << convertedChar << "\'" << std::endl;

    else if (value < INT_MIN || value > INT_MAX || std::isnan(value) || std::isinf(value))
        std::cout << "char : impossible" << std::endl;

    else
        std::cout << "char : non displayable" << std::endl;
}

void toInt(const std::string &str, const std::string &type)
{
    if (type == "char")
        std::cout << "int : " << static_cast<int>(str[0]) << std::endl;

    else if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff"
            || str == "nan" || str == "nanf" || str == "+inf" || str == "+inff")
        std::cout << "int : impossible" << std::endl;

    else
    {
        std::stringstream ss(str);
        long long temp;
        ss >> temp;

        // Check if the extraction succeeded and if the entire input was processed
        if (ss.fail() || !ss.eof() || temp < INT_MIN || temp > INT_MAX)
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(temp) << std::endl;
    }
}

void toFloat(const double &value, const std::string &type)
{
	float fl = static_cast<float>(value);
	(void)type;
	std::cout << std::fixed << std::setprecision(2) << "float : " << fl << "f" << std::endl;
}


void    ScalarConverter::convert(const std::string &str)
{
	std::cout << BLUE "Input: " << str << RESET << std::endl;
	std::string type =  findType(str);
	if (type == "unknown type") {
		std::cerr << RED "Error: "<< type << RESET << std::endl;
		return; }
	std::cout << GREEN "Type: " << type << "\n" RESET << std::endl;
	if (type == "char")
	{
		toChar(static_cast<double>(str[0]), type);
		toInt(str, type);
		toFloat(static_cast<double>(str[0]), type);
	}
	float nb = static_cast<float>(atof(str.c_str()));
	std::cout << nb << std::endl;
	toFloat(nb, type);
}