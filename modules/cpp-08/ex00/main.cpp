/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/07 11:07:54 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <deque>
#include "easyFind.hpp"
#include "utils.h"

int main() {
	// Tests for list container
	std::cout << MAGENTA "[LIST TESTS]" RESET << std::endl;
	std::list<int> lst;
	for (int i = 1; i <=10; ++i)
		lst.push_back(i);
	printContainer(lst);

	try {
		easyfind(lst, 5); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }

	try {
		easyfind(lst, 42); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }

	// Tests for vector container
	std::cout << MAGENTA "\n[VECTOR TESTS]" RESET << std::endl;
	std::vector<int> vec;
	for (int i = 1; i <=10; ++i)
		vec.push_back(i);
	printContainer(vec);

	try {
		easyfind(vec, 5); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }

	try {
		easyfind(vec, 42); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }

	// Tests for double-ended queue (deque) container
	std::cout << MAGENTA "\n[DEQUE TESTS]" RESET << std::endl;
	std::deque<int> deq;
	for (int i = 1; i <=10; ++i)
		deq.push_back(i);
	printContainer(deq);

	try {
		easyfind(deq, 5); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }

	try {
		easyfind(deq, 42); }
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl; }	
		
    return 0;
}
