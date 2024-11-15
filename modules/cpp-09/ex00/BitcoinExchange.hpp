/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:25 by acosi             #+#    #+#             */
/*   Updated: 2024/11/15 20:53:40 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>		// opening file, getline()
#include <sstream>		// string stream manipulation
#include <cstdlib>
#include <climits>

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
		int _match_flag;	// Flag to determine if an exact match was found in the database
		
		// Member functions
		bool openInputFile(const char *filename);
		const std::string findClosestDate(const std::string &date);
		void printOutput(const std::string &date, const double &value);

};


#endif