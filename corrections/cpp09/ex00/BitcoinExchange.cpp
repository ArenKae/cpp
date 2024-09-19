
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const char *arg)
{
	std::ifstream file(arg);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1) ;
	}
	std::string line = "";
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cout << "Error: " << line << std::endl;
			return ;
		}
		std::string date = line.substr(0, pos);
		std::string bitcoin = line.substr(pos + 1);
		float price = atof(bitcoin.c_str());
		_map.insert(std::make_pair(date, price));
	}
	file.close();
	// std::cout << "Default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
	// std::cout << "Copy constructor called." << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange & other)
{
	// std::cout << "Copy assignement operator called." << std::endl;
	this->_map = other._map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "Destructor called." << std::endl;
}

bool BitcoinExchange::bisextile(void)
{
	if (this->_year % 4 == 0) 
	{
		if (this->_year % 100 == 0)
		{
			if (this->_year % 400 == 0)
				return (true);
			return (false);
		}
		return (true);
	}
	return (false);
}

bool BitcoinExchange::check_date(std::string date)
{
	if (date.find_first_not_of("0123456789- ") != std::string::npos)
		return (false);
	else if (std::count(date.begin(), date.end(), '-') != 2)
		return (false);

	size_t first_dash = date.find("-");
	size_t second_dash = date.rfind("-");
	std::string year = date.substr(0, first_dash);
	std::string month = date.substr(first_dash + 1, second_dash - first_dash - 1);
	std::string day = date.substr(second_dash + 1);
	_year = atoi(year.c_str());
	int monthNum = atoi(month.c_str());
	int dayNum = atoi(day.c_str());
	if (monthNum > 12 || monthNum < 1)
		return (false);
	else if (monthNum == 2 && dayNum == 29 && bisextile() == false)
		return (false);
	else if (monthNum == 2 && dayNum > 29)
		return (false);
	else if (dayNum > 31 || dayNum < 1)
		return (false);
	else if (((monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11)) && (dayNum > 30))
		return (false);
	return (true);
}

void BitcoinExchange::check_print(char *arg)
{
	std::ifstream file(arg);
	if (!file.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		exit(1) ;
	}
	std::string line = "";
	std::getline(file, line);
	if (line.compare("date | value"))
	{
		std::cout << "Error: not good first line." << std::endl;
		exit(1);	
	}
	while (std::getline(file, line))
	{
		if (line[11] != '|' || std::count(line.begin(), line.end(), '|') != 1 || std::count(line.begin(), line.end(), 'f') > 1)
		{
			std::cout << "Error: Bad input => " <<  line << std::endl;
			continue ;
		}
		else if (line.find_first_not_of("0123456789-|.f ") != std::string::npos || line.empty())
		{
			std::cout << "Error: Bad input => " <<  line << std::endl;
			continue ;
		}

		std::string date = line.substr(0, 10);
		size_t pos_value = line.find("|");
		std::string value = "";
		if (pos_value != std::string::npos)
		{
			try
			{
				value = line.substr(pos_value + 2);
			}
			catch (const std::exception &e)
			{
				std::cout << "Error: Bad input." << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Error: Bad input => " <<  line << std::endl;
			continue ;
		}
		if (atof(value.c_str()) < 0)
			std::cout << "Error: not a positive number. " << std::endl;
		else if (atof(value.c_str()) > 1000)
			std::cout << "Error: too large number. " << std::endl;
		else if (value.empty())
			std::cout << "Error: empty value. " << std::endl;
		else if (value.find_first_not_of("0123456789.f") == 0)
			std::cout << "Error: Bad input => " <<  line << std::endl;
		else
			get_value(date, std::atof(value.c_str()));
		line = "";
	}
	file.close();
	return ;
}

void BitcoinExchange::get_value(std::string date, float quantity)
{
	std::map<std::string, float>::iterator iterator = _map.lower_bound(date);
	float value = 0;
	if (_year < 2010)
		std::cout << date << " => " << quantity << " = 0" << std::endl;
	else if (iterator != _map.end() && date.compare(iterator->first) == 0)
	{
		value = (iterator)->second;
		std::cout << date << " => " << quantity << " = " << (value * quantity) << std::endl;
	}
	else if (iterator != _map.begin())
	{
		value = (--iterator)->second;
		std::cout << date << " => " << quantity << " = " << (value * quantity) << std::endl;
	}
	else
		std::cout << date << " => " << quantity << " = " << (value * quantity) << std::endl;
}
