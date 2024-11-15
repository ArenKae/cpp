/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:31:32 by acosi             #+#    #+#             */
/*   Updated: 2024/11/15 17:42:57 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include "utils.h"

/*	std::stack is a container adapter that provides a Last In, First Out (LIFO) data structure, 
	meaning the last element added to the stack will be the first one removed. As an adapter, it is 
	not a standalone container, but it's built ont top of one to adapt it (deque is used by default). */

template <typename T>
class MutantStack : public std::stack<T> // Inerit from stack to access functions like push, pop...
{
	public:
		// Default constructor #OrthodoxCanoncialForm
		// Initialize an empty stack.
		MutantStack(void) : std::stack<T>() {};
		
		// Copy constructor #OrthodoxCanoncialForm
		// Use the copy constructor from std::stack to copy the internal container of src.
		MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {};

		// Destructor #OrthodoxCanoncialForm
		~MutantStack() {};

		// Overloaded assignment operator #OrthodoxCanoncialForm
		// Use the assignment operator from std::stack to copy the internal container of src int this*.
		MutantStack& operator=(const MutantStack<T> &src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return *this;
		}
	
		// Define the iterator aliases for readability
		typedef	typename std::stack<T>::container_type::iterator iterator;

		/*	this->c is a protected member of std::stack representing the underlying container.
			We can then access its own begin() and end() members to allow iteration. */
		iterator begin() { return this->c.begin();};
		iterator end() { return this->c.end();};
};

// Template helper function for printContainer
template <typename T>
struct PrintFunction {
    void operator()(const typename T::value_type& item) const {
        std::cout << item << " ";
    }
};

// Template function to print the content of a container
template <typename T>
void printContainer (T& container, const std::string &name) {
	std::cout << BLUE << name << RESET " = [ ";
    std::for_each(container.begin(), container.end(), PrintFunction<T>());
    std::cout << "]" << std::endl;
}

// Template function to print Stack infos and make the main program more readable
template <typename T>
void printStackInfos(const T& container, const std::string &name) {
	std::cout << BLUE << name << RESET " size is " GREEN << container.size() << RESET 
	" and the last element is " YELLOW << container.top() << RESET << std::endl;
}

// Template function to print list infos and make the main program more readable
template <typename T>
void printListInfos (const T& container, const std::string &name) {
	std::cout << BLUE << name << RESET " size is " GREEN << container.size() << RESET 
	" and the last element is " YELLOW << container.back() << RESET << std::endl;
}

#endif