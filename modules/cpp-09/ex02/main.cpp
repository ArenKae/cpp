/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 07:00:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "PmergeMe.hpp"
#include "utils.h"

static bool isPositiveInt(const std::string &arg)
{
	for (size_t i = 0; i < arg.length(); ++i)
		if (!isdigit(arg[i])) {
			throw std::invalid_argument("Invalid input");
			return false; }
	return !arg.empty(); // Return false if arg is empty, true otherwise.
}

static bool isValidInput(const std::string &arg)
{
	try { isPositiveInt(arg); }
	catch (const std::exception& e) {
    	std::cerr << RED "Error: " << e.what() << RESET << std::endl; 
		return false; }
	return true;
}

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << RED "Error: No input provided." RESET << std::endl;
		return 1; }

	// Instanciate the class and the containers
	PmergeMe pm;
	std::vector<int> vec;
	std::list<int> lst;

	// Filling the containers
	for (int i = 1; i < ac; ++i) {
		if (!isValidInput(av[i]))
			return 1;
		int num = std::atoi(av[i]);
		vec.push_back(num);
		lst.push_back(num); }
		
	// Display unsorted sequence
	std::cout << "Before: ";
    // for (size_t i = 0; i < vec.size(); ++i) std::cout << vec[i] << " ";
    // std::cout << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) std::cout << YELLOW << *it << " ";
    std::cout << RESET << std::endl;

	// Sort and measure time for list
	clock_t start = clock();
	pm.sortList(lst);
	clock_t end = clock();
	double lstTime = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;

	// Display sorted sequence
	std::cout << "After: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) std::cout << GREEN << *it << " ";
    std::cout << RESET << std::endl;

	// Display times
    std::cout << "Time to process a range of " << lst.size() 
	<< " elements with std::list: " BLUE << lstTime << " ms" RESET << std::endl;

	return 0;
}