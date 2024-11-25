/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/25 08:41:06 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "utils.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << RED "Error" RESET << std::endl;
		return EXIT_FAILURE; }
	
	try {
		RPN rpn;
		std::cout << GREEN << rpn.compute(av[1]) << RESET << std::endl; }
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl; }
	
	return EXIT_SUCCESS;
}