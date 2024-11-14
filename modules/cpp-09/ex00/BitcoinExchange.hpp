/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:25 by acosi             #+#    #+#             */
/*   Updated: 2024/11/14 04:05:45 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>		// opening file, getline()
#include <sstream>		// string stream manipulation
#include <cstdlib>		// atof()

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
		
		void printData(const std::string &key);

	private:
		// Map container to store the database
		std::map<std::string, double> _data;
		
		// Member functions
		bool openInputFile(const char *filename);
		std::string findClosestDate(const std::string &date);

};


#endif