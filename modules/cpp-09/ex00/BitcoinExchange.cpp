/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:32 by acosi             #+#    #+#             */
/*   Updated: 2024/11/25 09:55:33 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.h"

// Static helper functions declarations
static bool isValidFormat(const std::string &line);
static bool isValidNumber(const std::string &valueStr);
static bool isValidDate(const std::string &date);

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

// Default Constructor
BitcoinExchange::BitcoinExchange(void) : _color_flag(1) {}

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

bool BitcoinExchange::processInput(const char *filename)
{
	// Opening input file
	std::ifstream file(filename);
	if (!file.is_open() || file.fail())
		return false;

	std::string line;
	getline(file, line); // Skip first line (header)
	
	while (getline(file, line))
	{
		if (line.empty() || !isValidFormat(line)) // Skip the search if an error was found
			continue;
		
		std::stringstream ss(line);
		std::string date, valueStr;
		if (getline(ss, date, '|') && getline(ss, valueStr))
		{
			date.erase(date.find_last_not_of(" \t") + 1); // Trim trailing spaces
			std::string closestDate = findClosestDate(date);
			double value = atof(valueStr.c_str());
			printOutput(closestDate, value);
			_color_flag = 1;	// Reset the color flag for output
		}
	}
	file.close();
	return true;
}

// Parse the map with an iterator to find the closest date.
const std::string BitcoinExchange::findClosestDate(const std::string &date)
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
		_color_flag = 0;	// Update the flag to get correct color in output
	}
	return it->first; // Return the key holding the date
}

void BitcoinExchange::printOutput(const std::string &date, const double &value)
{
	std::cout << (_color_flag == 1 ? GREEN : YELLOW) << 
	date << " => " << value << " = " << value * _data[date] << RESET << std::endl;
}

/**********************************/
/*******[ HELPER FUNCTIONS ]*******/
/**********************************/

// Check the validity of the current line from the input file
static bool isValidFormat(const std::string &line)
{
	size_t delimiterPos = line.find('|');
	
	// Check if the delimiter exists and is not at the start or end
	if (delimiterPos == std::string::npos ||  delimiterPos == 0 || delimiterPos == line.size() - 1) {
		std::cerr << RED "Error: invalid input =>  " << line << RESET << std::endl;
		return false; }
		
 	// Extract date and value parts
	std::string date = line.substr(0, delimiterPos);
	std::string value = line.substr(delimiterPos + 1);

	// Trim leading and trailing spaces
	date.erase(0, date.find_first_not_of(" \t"));
	date.erase(date.find_last_not_of(" \t") + 1);
	value.erase(0, value.find_first_not_of(" \t"));
	value.erase(value.find_last_not_of(" \t") + 1);

	// Check if the date is in YYYY-MM-DD format
	if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
		std::cerr << RED "Error: invalid date format. Use YYYY-MM-DD." RESET << std::endl;
		return false; }

	if (!isValidDate(date))
		return false;

	if (!isValidNumber(value))
		return false;

	return true;
}

// Check that the date from the input file is valid.
static bool isValidDate(const std::string &date)
{
	// Extract year, month, and day from the date string
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	// Validate year
	if (year < 2009 || (year == 2009 && month == 1 && day == 1)) {
		std::cerr << RED "Error: no entry in database before 2009-01-02" RESET << std::endl;
		return false; }
	
	// Validate month
	if (month < 1 || month > 12) {
		std::cerr << RED "Error: invalid date. => " << date << RESET << std::endl;
		return false; }
	
	// Validate day based on the month
	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDays = daysInMonth[month - 1];
	
	// Adjust for leap year in February
	if (month == 2 && year % 4 == 0)
		maxDays = 29;
	
	if (day < 1 || day > maxDays) {
		std::cerr << RED "Error: invalid date. => " << date << RESET << std::endl;
		return false; }

	return true;
}

// Check that the value from the input file is a valid number.
static bool isValidNumber(const std::string &valueStr)
{
	if (valueStr.empty()) {
		std::cerr << RED "Error: missing number value." RESET << std::endl;
		return false; }

	// Create an input stream stream (iss) from the value string.
	// Attempt to convert it to a double and check if the operation failed.
	std::istringstream iss(valueStr);
	double value;
	iss >> value;
	if (iss.fail() || !iss.eof()) {
		std::cerr << RED "Error: invalid number." RESET << std::endl;
		return false; }
	
	if (value > static_cast<double>(INT_MAX)) {
		std::cerr << RED "Error: too large a number." RESET << std::endl;
		return false; }

	if (value < 0) {
		std::cerr << RED "Error: not a positive number." RESET << std::endl;
		return false; }

	return true;
}