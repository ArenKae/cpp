/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:10:13 by acosi             #+#    #+#             */
/*   Updated: 2024/11/07 10:02:30 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <exception>
#include <list>
#include "utils.h"

// Custom exception class
class ValueNotFoundException : public std::exception {
private:
    int _value;

public:
    // Constructor to accept an error code
    ValueNotFoundException(int value) : _value(value) {}

    // Override the what() method to return a message including the error code
    const char* what() const throw() {
        std::cout << _value << " : ";
        return "value not found";
    }
};

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw ValueNotFoundException(value);
	std::cout << GREEN << *it << " : value found" RESET << std::endl;
	return it;
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
void printContainer(const T& container) {
    std::for_each(container.begin(), container.end(), PrintFunction<T>());
    std::cout << std::endl;
}

#endif