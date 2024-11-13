/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:50:25 by acosi             #+#    #+#             */
/*   Updated: 2024/11/13 23:08:41 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <iostream>

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
		bool loadData(const std::string &filename);

	private:
		std::map<std::string, double> data;
};


#endif