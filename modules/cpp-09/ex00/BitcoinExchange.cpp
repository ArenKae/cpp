/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:32 by acosi             #+#    #+#             */
/*   Updated: 2024/11/14 05:07:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.h"

// Helper functions declarations
std::string trim(const std::string& str);

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

// Default Constructor
BitcoinExchange::BitcoinExchange(void) {}

// Copy Constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) { *this = src; }

// Assignment Operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

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
			
			std::string closestDate = findClosestDate(date);
			std::cout << GREEN "closest match: " << closestDate << " , " << _data[closestDate] << RESET << std::endl;
			}
	}
	file.close();
	return true;
}

bool BitcoinExchange::processInput(const char *filename)
{
	if (!openInputFile(filename))
		return false;
	
	return true;
	
}

/**********************************/
/*******[ HELPER FUNCTIONS ]*******/
/**********************************/

// Parse the map with an iterator to find the closest date.
std::string BitcoinExchange::findClosestDate(const std::string &date)
{
	// The iterator is initialized with the lower_bound() method to find the first key 
	// that is equal or greater than the argument.
	std::map<std::string, double>::iterator it = _data.lower_bound(date);
	
	// If it = end(), no greater or equal entry were found.
	// If the date in it doesn't exactly match the one we search for, it's an in-between case.
    if (it == _data.end() || it->first != date)
	{
        if (it == _data.begin()) // Error: no earlier date
			return "";
        --it;	// Go to the closest earlier date
    }
    return it->first; // Return the key holding the date
}

// Trim trailing spaces in a string
std::string trim(const std::string& str)
{
    std::string::size_type end = str.size();
    while (end > 0 && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;
    return str.substr(0, end);
}

void BitcoinExchange::printData(const std::string &key)
{
	std::cout << key << " , " << _data[key] << std::endl;
}