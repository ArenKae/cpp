/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/27 02:03:36 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include "utils.h"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << RED "Error" RESET << std::endl;
		return 1; }
	
	try {
		RPN rpn;
		std::cout << GREEN << rpn.compute(av[1]) << RESET << std::endl; }
	catch (const std::exception &e) {
		std::cerr << RED << e.what() << RESET << std::endl; }
}