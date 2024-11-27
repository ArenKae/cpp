/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/27 02:53:49 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.h"

static bool isPositiveInt(const std::string &arg)
{
	for (size_t i = 0; i < arg.length(); ++i)
		if (!isdigit(arg[i]))
			return false;
	return !arg.empty(); // Return false if arg is empty, true otherwise.
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << RED "Error: No input provided." RESET << std::endl;
		return 1; }

	std::vector<int> vec;
	std::list<int> lst;

	try {
		for (int i = 1; i < ac; ++i) {
			if (!isPositiveInt(av[i]))
				throw std::invalid_argument("Invalid input");
			int num = std::atoi(av[i]);
			vec.push_back(num);
			lst.push_back(num); }
		
		// Display unsorted sequence
		std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
        std::cout << std::endl;
	}
	catch (const std::exception& e) {
        std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
}