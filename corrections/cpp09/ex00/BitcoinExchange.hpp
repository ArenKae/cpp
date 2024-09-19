#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <algorithm>

class BitcoinExchange
{
	public:
		BitcoinExchange(const char *arg);
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator=(const BitcoinExchange & other);
		~BitcoinExchange(void);
		bool bisextile();
		bool check_date(std::string date);
		void check_print(char *arg);
		void get_value(std::string date, float quantity);

	private:
		int	_year;
		std::map<std::string, float> _map;
};

#endif
