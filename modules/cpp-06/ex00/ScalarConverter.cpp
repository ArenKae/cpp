/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:45:04 by acosi             #+#    #+#             */
/*   Updated: 2024/10/28 17:00:44 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"

// Test if the parameter is a char type.
static bool    isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return true;
	else
		return false;
}

// Test if the parameter is an integer type.
static bool    isInt(const std::string &str)
{
    int    nb;
    std::istringstream    iss(str);	// Creates an input string stream object (iss) using the string str.
    iss >> nb;	// The >> operator attempts to convert iss into the type of nb (int).
	
	// Returns true if there are no extra characters left in the stream and if no conversion errors occurs.
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a double type.
static bool    isDouble(const std::string &str)
{
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
		return true;
    double    nb;
    std::istringstream    iss(str);
    iss >> nb;
    return (iss.eof() && !iss.fail());
}

// Test if the parameter is a float type.
static bool    isFloat(const std::string &str)
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
    return false;
}

static std::string findType(const std::string &str)
{
	int    type = -1;

    bool (*fuctions[])(const std::string &str) = {&isChar, &isInt, &isFloat, &isDouble,};
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
			return "int";
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

void toChar(const std::string &str, const std::string &type)
{
	double value;
	if (type == "char")
		value = static_cast<int>(str[0]);
	else if (type == "int" || type == "double" || type == "float")
		value = atof(str.c_str());
	
	if (type == "char" && std::isprint(value))
		std::cout << "char : \'" << static_cast<char>(value) << "\'" << std::endl;

	else if ((type == "int" || type == "double" || type == "float") && value >= 32 && value <= 126)
        std::cout << "char : \'" << static_cast<char>(value) << "\'" << std::endl;

    else if (value < INT_MIN || value > INT_MAX || std::isnan(value) || std::isinf(value))
        std::cout << "char : impossible" << std::endl;

    else
        std::cout << "char : non displayable" << std::endl;
}

void toInt(const std::string &str, const std::string &type)
{
	std::stringstream iss(str);

    if (type == "char")
        std::cout << "int : " << static_cast<int>(str[0]) << std::endl;

    else if (str == "inf" || str == "inff" || str == "-inf" || str == "-inff"
            || str == "nan" || str == "nanf" || str == "+inf" || str == "+inff")
        std::cout << "int : impossible" << std::endl;

    else if (type == "int")
    {
        long long  temp;
        iss >> temp;
	
        if (iss.fail() || !iss.eof() || temp < INT_MIN || temp > INT_MAX)
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(temp) << std::endl;
    }
	
	else if (type == "double")
    {
        double  temp;
        iss >> temp;

        if (iss.fail() || !iss.eof())
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(temp) << std::endl;
    }
	
	else if (type == "float")
    {
        float  temp;
		std::string trim = str.substr(0, str.size() - 1); // Removes the final 'f'
		std::istringstream iss(trim);
        iss >> temp;

        if (iss.fail() || !iss.eof())
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(temp) << std::endl;
    }
}

void toFloat(const std::string &str, const std::string &type)
{
	const double &value = static_cast<double>(atof(str.c_str()));
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
	
	toChar(str, type);
	toInt(str, type);
	toFloat(str, type);
	//float nb = static_cast<float>(atof(str.c_str()));
}