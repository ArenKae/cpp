/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 07:23:01 by acosi             #+#    #+#             */
/*   Updated: 2024/11/13 04:04:23 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include "MutantStack.hpp"
#include "utils.h"


int main()
{
	// Tests for basic functionalities of the MutantStack class.
	std::cout << MAGENTA "[MUTANT STACK TESTS]" RESET << std::endl;
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	printContainer(mstack, "mstack");
	printStackInfos(mstack, "mstack");
	
	mstack.pop();
	std::cout << RED "-> mstack last element poped!" RESET << std::endl;
	printContainer(mstack, "mstack");
	printStackInfos(mstack, "mstack");
	
	mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
	std::cout << RED "-> 4 elements were pushed to mstack..." RESET << std::endl;
	printContainer(mstack, "mstack");
	printStackInfos(mstack, "mstack");
	
	std::cout << RED "-> Creating iterator it..." RESET << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "*it = " << *it << std::endl;
	std::cout << RED "-> Incrementing iterator it..." RESET << std::endl;
	std::cout << "*it = " << *++it << std::endl;
	std::cout << RED "-> Decrementing iterator it..." RESET << std::endl;
	std::cout << "*it = " << *--it << std::endl;
	
	
	std::cout << RED "-> Iterating through mstack using begin iterator :" RESET << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << RED "-> Iterating through mstack using end iterator :" RESET << std::endl;
	for (MutantStack<int>::iterator ite = --mstack.end(); ite != --mstack.begin(); --ite)
        std::cout << *ite << " ";
	std::cout << std::endl;

	// Same tests with a std::list container to compare output
	std::cout << MAGENTA "\n[LIST TESTS]" RESET << std::endl;
	std::list<int> lst;
	
	lst.push_back(5);
	lst.push_back(17);
	printContainer(lst, "lst");
	printListInfos(lst, "lst");
	
	lst.pop_back();
	std::cout << RED "-> lst last element poped!" RESET << std::endl;
	printContainer(lst, "lst");
	printListInfos(lst, "lst");
	
	lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
	std::cout << RED "-> 4 elements were pushed to lst..." RESET << std::endl;
	printContainer(lst, "lst");
	printListInfos(lst, "lst");
	
	std::cout << RED "-> Creating iterator lit..." RESET << std::endl;
	std::list<int>::iterator lit = lst.begin();
	std::cout << "*lit = " << *lit << std::endl;
	std::cout << RED "-> Incrementing iterator lit..." RESET << std::endl;
	std::cout << "*lit = " << *++lit << std::endl;
	std::cout << RED "-> Decrementing iterator lit..." RESET << std::endl;
	std::cout << "*lit = " << *--lit << std::endl;
	
	std::cout << RED "-> Iterating through lst using begin iterator :" RESET << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << RED "-> Iterating through lst using end iterator :" RESET << std::endl;
	for (std::list<int>::iterator ite = --lst.end(); ite != --lst.begin(); --ite)
        std::cout << *ite << " ";
	std::cout << std::endl;

    return 0;
}
