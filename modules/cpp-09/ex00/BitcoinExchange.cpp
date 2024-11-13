/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:32 by acosi             #+#    #+#             */
/*   Updated: 2024/11/13 23:13:33 by acosi            ###   ########.fr       */
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

bool BitcoinExchange::loadData(const std::string &filename)
{
	
}