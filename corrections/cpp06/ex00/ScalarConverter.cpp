/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 07:31:22 by dtassel           #+#    #+#             */
/*   Updated: 2024/10/15 04:44:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::findType(const std::string &input)
{
    if (input == "inf" || input == "+inf" || input == "-inf")
        return ("double");
    else if (input == "nan")
        return ("double");
    else if (input == "inff" || input == "+inff" || input == "-inff")
        return ("float");
    else if (input == "nanf")
        return ("float");
    else if (isChar(input))
        return ("char");
    else if (isInt(input))
    {
        return ("int");
    }
    else if (isFloat(input))
        return ("float");
    else if (isDouble(input))
        return ("double");
    else
        return ("error");
}


void ScalarConverter::convert(const std::string &input)
{
    int p = 0;
    std::string type = findType(input);
    std::cout << "type : " << type << std::endl;
    p = input.find('.');
    if (p != -1)
        p = (input.length() -1) - p;
    if (type == "error")
        std::cerr << "Error : Invalid Argument" << std::endl;
    if (type == "int")
    {
        int value = atoi(input.c_str());
        toChar(static_cast<double>(value), input, type);
        toInt(input, type);
        toFloat(static_cast<double>(value), input, p, type);
        toDouble(static_cast<double>(value), input, p, type);
    }
    else if (type == "float")
    {
        float value = static_cast<float>(atof(input.c_str()));
        toChar(static_cast<double>(value), input, type);
        toInt(input, type);
        toFloat(static_cast<double>(value), input, p, type);
        toDouble(static_cast<double>(value), input, p, type);
    }
    else if (type == "double")
    {
        double value = atof(input.c_str());
        toChar(value, input, type);
        toInt(input, type);
        toFloat(value, input, p, type);
        toDouble(value, input, p, type);
    }
    else if (type == "char")
    {
        char value = input[0];
        toChar(static_cast<double>(value), input, type);
        toInt(input, type);
        toFloat(static_cast<double>(value), input, p, type);
        toDouble(static_cast<double>(value), input, p, type);
    }
}

bool ScalarConverter::isChar(const std::string &input)
{
    if (input.length() == 1 && !isdigit(input[0]))
            return true;
    return false;
}

bool ScalarConverter::isInt(const std::string &input)
{
    size_t i = 0;
    if (input[0] == '+' || input[0] == '-')
        i++;
    while (isdigit(input[i]))
        i++;

    if (input.length() != i)
        return false;

    char *end;
    long long val = strtoll(input.c_str(), &end, 10);

    if (end != input.c_str() + input.size() || val < INT_MIN || val > INT_MAX)
        return false;

    return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
    size_t i = 0;
    int p = 0;
    int f = 0;

    if (input[input.length() - 1] == 'f')
    {
        if (input[input.length() - 2] == '.')
            return (false);
    }
    else
        return false;
    if (input[0] == '.' || input[0] == 'f')
            return false;
    if (input[0] == '+' || input[0] == '-')
        i++;
    while (isdigit(input[i]) || input[i] == '.' || input[i] == 'f')
    {
        if (input[i] == '.')
            p++;
        if (input[i] == 'f')
            f++;
        i++;
    }
    if (input.length() == i && p == 1 && f == 1)
        return true;
    char *end;
    strtof(input.c_str(), &end);

    if (*end == 'f' && end == input.c_str() + input.size() - 1)
        return true;
    return false;
}

bool ScalarConverter::isDouble(const std::string &input)
{
    size_t i = 0;
    int p = 0;

    if (input[0] == '+' || input[0] == '-')
        i++;
    if (input[i] == '.' || input[input.length() - 1] == '.')
            return false;
    while (isdigit(input[i]) || input[i] == '.')
    {
        if (input[i] == '.')
            p++;
        i++;
    }
    if (input.length() == i && p == 1)
        return true;
    char *end;
    strtod(input.c_str(), &end);

    if (end == input.c_str() + input.size())
        return true;
    return false; 
}

void ScalarConverter::toInt(const std::string &input, const std::string &type)
{
    if (type == "char")
    {
        std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
    }
    else if (input == "inf" || input == "inff" || input == "-inf" || input == "-inff"
            || input == "nan" || input == "nanf" || input == "-nan" || input == "-nanf")
        std::cout << "int : impossible" << std::endl;
    else
    {
        long long temp = strtoll(input.c_str(), NULL, 10);
        if (temp < INT_MIN || temp > INT_MAX || input == "nan" || input == "+inf" || input == "-inf")
            std::cout << "int : impossible" << std::endl;
        else
            std::cout << "int : " << static_cast<int>(temp) << std::endl;
    }
}

void ScalarConverter::toDouble(const double &value, const std::string &input, const int &p, const std::string &type)
{
    if (p != -1 && type == "float")
        std::cout << std::fixed << std::setprecision(p - 1) << "double : "  << value << std::endl;
    else if (p != -1)
        std::cout << std::fixed << std::setprecision(p) << "double : " << value << std::endl;
    else if (type == "char")
        std::cout << std::fixed << std::setprecision(1) << "double : " << static_cast<double>(input[0]) << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "double : " << value << std::endl;
}

void ScalarConverter::toFloat(const double &value, const std::string &input, const int &p, const std::string &type)
{
    float nb;
    nb = static_cast<float>(value);
    if (p != -1 && type == "float")
        std::cout << std::fixed << std::setprecision(p - 1) << "1float : " << nb << "f" << std::endl;
    else if (p != -1)
        std::cout << std::fixed << std::setprecision(p) << "2float : " << nb << "f" << std::endl;
    else if (type == "char")
        std::cout << std::fixed << std::setprecision(1) << "3float : " << static_cast<float>(input[0]) << "f" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "4float : " << nb << "f" << std::endl;
}

void ScalarConverter::toChar(const double &value, const std::string &input, const std::string &type)
{
    char convertedChar = static_cast<char>(value);
    if ((type == "int" || type == "double" || type == "float") && value >= 32 && value <= 126)
    {
        std::cout << "char : '" << convertedChar << "\'" << std::endl;
    }
    else if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX) || isnan(value) || isinf(value))
    {
        std::cout << "char : impossible" << std::endl;
    }
    else if (type == "char" && isprint(input[0]))
    {
        std::cout << "char : " << "\'" << input[0] << "\'" << std::endl;
    }
    else
    {
        std::cout << "char : Non displayable" << std::endl;
    }
}


