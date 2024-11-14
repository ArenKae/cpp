/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:25 by acosi             #+#    #+#             */
/*   Updated: 2024/11/14 01:52:03 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>		// opening file, getline()
#include <sstream>		// stringstream manipulation
#include <cstdlib>		// atof()
#include <string>


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
		bool openInputFile(const char *filename);
		
		void printData(const std::string &key);

	private:
		std::map<std::string, double> _data;

};


#endif