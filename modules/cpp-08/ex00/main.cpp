/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/07 10:04:24 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include "utils.h"

int main() {
	std::cout << MAGENTA "[INT CONTAINER TESTS]" RESET << std::endl;
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

    return 0;
}
