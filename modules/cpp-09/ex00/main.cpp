/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/14 01:08:47 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << RED << "Error: wrong number of arguments\n" YELLOW 
		"Usage: " RESET "./btc <" BLUE "file" RESET ">"<< std::endl;
		return 1; }
	
	BitcoinExchange btc;
	if (!btc.loadData("data.csv")) {
		std::cerr << RED "Error: could not open database." RESET << std::endl;
		return 1; }
	
	if (!btc.processInput(av[1]))
		return 1;

	btc.printData("2012-11-27");
	
    return 0;
}
