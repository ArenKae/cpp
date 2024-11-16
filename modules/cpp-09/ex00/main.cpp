/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/16 18:32:22 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "utils.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << RED << "Error: wrong number of arguments\n" YELLOW 
		"Usage: " RESET "./btc <" BLUE "file" RESET ">"<< std::endl;
		return EXIT_FAILURE; }
	
	BitcoinExchange btc;
	
	if (!btc.loadData("data.csv")) {
		std::cerr << RED "Error: could not open database." RESET << std::endl;
		return EXIT_FAILURE; }
	
	if (!btc.processInput(av[1])) {
		std::cerr << RED "Error: could not open input file." RESET << std::endl;
		return EXIT_FAILURE; }

    return EXIT_SUCCESS;
}