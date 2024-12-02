/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:25 by acosi             #+#    #+#             */
/*   Updated: 2024/12/02 16:06:37 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>		// opening file, getline()
#include <sstream>		// string stream manipulation
#include <cstdlib>		// atof()
#include <climits>		// INT_MAX

class BitcoinExchange
{
	public:
		// Default constructor #OrthodoxCanoncialForm
		BitcoinExchange(void);
		
		// Copy constructor #OrthodoxCanoncialForm
		BitcoinExchange(const BitcoinExchange &src);

		// Destructor #OrthodoxCanoncialForm
		~BitcoinExchange();

		// Overloaded assignment operator #OrthodoxCanoncialForm
		BitcoinExchange& operator=(const BitcoinExchange &src);

		// Member Functions
		bool loadData(const char *filename);
		bool processInput(const char *filename);

	private:
		std::map<std::string, double> _data; // Map container to store the database
		int _color_flag;  // Flag to change the color in output if an exact or an closest match was found
		
		// Member functions
		bool openInputFile(const char *filename);
		const std::string findClosestDate(const std::string &date);
		void printOutput(const std::string &date, const std::string &ClosestDate, const double &value);
};

#endif