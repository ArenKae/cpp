/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 06:08:50 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 05:31:11 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "utils.h"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << RED << "Error: Wrong number of arguments." << RESET << std::endl;
		std::cerr << YELLOW << "Usage: " RESET << "./harlFilter " << "<" << BLUE 
		<< "LEVEL OF COMPLAIN" << RESET << "> (choose between: DEBUG, INFO, WARNING, ERROR)"  << std::endl;
		return 1; }

	Harl Harl;
	std::string level = av[1];
	Harl.complain(level);
	
	return 0;
}