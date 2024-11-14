/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:32 by acosi             #+#    #+#             */
/*   Updated: 2024/11/14 02:01:31 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.h"

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

// Default Constructor
BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << "BitcoinExchange default constructor called." << std::endl;
}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
	//std::cout << "BitcoinExchange copy constructor called." << std::endl;
}

// Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "BitcoinExchange destructor called." << std::endl; 
}

/**********************************/
/*******[ MEMBER FUNCTIONS ]*******/
/**********************************/

bool BitcoinExchange::loadData(const char *filename)
{
	// Opening database file
	std::ifstream file(filename);
	if (!file.is_open() || file.fail())
		return false;

	std::string line, date;
    double rate;
    
    // Read the first line (header) to skip it
    getline(file, line);

    // Loop through each remaining line
    while (getline(file, line))
	{
    	std::stringstream ss(line); // Create a stringstream from the current line

		// Read up to the first comma to extract the date. 
		// The >> operator will exctract the remaining characters into rate and convert it to a double
    	if (getline(ss, date, ',') && ss >> rate)
        	_data[date] = rate;  // Store the date and rate in the map
	}

    file.close();
    return true;
}

// Trim trailing spaces in a string
std::string trim(const std::string& str) {
    std::string::size_type end = str.size();
    while (end > 0 && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
        --end;
    }
    return str.substr(0, end);
}


bool BitcoinExchange::openInputFile(const char *filename)
{
	// Opening input file
	std::ifstream file(filename);
	if (!file.is_open() || file.fail())
		return false;

	std::string line;

	getline(file, line); // Skip first line (header)
	while (getline(file, line))
	{
        std::stringstream ss(line);
        std::string date, valueStr;
        if (getline(ss, date, '|') && getline(ss, valueStr))
		{
            date = trim(date);
            double value = atof(valueStr.c_str());
			std::cout << "input: " << date << " | " << value << std::endl;
			
			std::map<std::string, double>::iterator it = _data.find(date);
			if (it != _data.end())
				std::cout << GREEN "match: " << it->first << " , "  << it->second << RESET << std::endl;
			else
				std::cout << RED "No match found." RESET << std::endl;
		}

	}
		

	return true;
	
}

bool BitcoinExchange::processInput(const char *filename)
{
	if (!openInputFile(filename))
		return false;
	
	return true;
	
}


void BitcoinExchange::printData(const std::string &key)
{
	std::cout << key << " , " << _data[key] << std::endl;
}