/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/30 07:38:16 by acosi            ###   ########.fr       */
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
	for (size_t i = 0; i < vec.size(); ++i) std::cout << YELLOW << vec[i] << " ";
	std::cout << RESET << std::endl;

	// Sort and measure time for vector
	clock_t start = clock();
	pm.sortVector(vec);
	clock_t end = clock();
	double vecTime = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;

	// Sort and measure time for list
	start = clock();
	pm.sortList(lst);
	end = clock();
	double lstTime = static_cast<double>(end - start) * 1000 / CLOCKS_PER_SEC;

	// Display sorted sequence
	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << GREEN << vec[i] << " ";
	std::cout << RESET << std::endl;
	/*for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << GREEN << *it << " ";
	std::cout << RESET << std::endl;*/

	// Display times
	/*	In a vector, elements are stored contiguously in memory, so every access 
		or insertion operation is constant time O(1).
		A (doubly linked) list where every element contains a pointer to the next one. The data
		is scattered in memory, so access is slower and insertion requires to create a new node.
		Hence, the vector is generally faster to sort. */
	std::cout << "Time to sort a vector of " << vec.size() << " elements: " BLUE << vecTime << " ms" RESET << std::endl;
	std::cout << "Time to sort a list of " << lst.size() << " elements: " BLUE << lstTime << " ms" RESET << std::endl;
	return 0;
}