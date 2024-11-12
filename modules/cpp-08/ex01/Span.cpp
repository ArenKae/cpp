/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:09 by acosi             #+#    #+#             */
/*   Updated: 2024/11/12 21:07:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include "Span.hpp"
#include "utils.h"

/***********************************/
/****[ ORTHODOX CANONICAL FORM ]****/
/***********************************/

// Default constructor
Span::Span(void) : _size(1)
{
	std::cout << GREEN "Default span created." RESET << std::endl;
}

// Size constructor
Span::Span(unsigned int N) : _size(N)
{
	std::cout << GREEN "Span of size " YELLOW << _size << GREEN " created." RESET << std::endl;
}

// Copy constructor
Span::Span(const Span &src) : _sp(src._sp), _size(src._size)
{
	std::cout << GREEN "Copy of span of size " YELLOW << _size << GREEN " created." RESET << std::endl;
}

// Destructor
Span::~Span()
{
	//std::cout << "Span destructor called." << std::endl;
}

// Copy assignment operator
Span& Span::operator=(const Span &src)
{
	if (this != &src) {
		_sp = src._sp;
		_size = src._size; }
	return *this;
}

/**********************************/
/*******[ MEMBER FUNCTIONS ]*******/
/**********************************/

// Add a single number to the Span
void Span::addNumber(int num)
{
	if (_sp.size() >= _size)
		throw SpanFullException(num);
	_sp.push_back(num);
	std::cout << "Value " BLUE << num << RESET " successfully added. Span capacity: "
	<< YELLOW << _sp.size()  << "/" << _size << RESET << std::endl;
}

// Find the shortest span
int Span::shortestSpan() const
{
	if (_sp.size() < 2)
			throw std::runtime_error("Not enough elements to find a span.");
	
	// Create a copy of _sp and sort it in ascending order
	std::vector<int> sorted(_sp);
	std::sort(sorted.begin(), sorted.end());

	// min_span is initialized with the largest possible value and will shrink every time a shorter span is found.
	int min_span = std::numeric_limits<int>::max();
	int current_span = 0;

	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		current_span = sorted[i + 1] - sorted[i];
		if (current_span < min_span)
			min_span = current_span;
	}
	return min_span;
}

// Find the longest span
int Span::longestSpan() const
{
	if (_sp.size() < 2)
			throw std::runtime_error("Not enough numbers to find a span.");
	
	// Find the smallest and the largest values in the Span
	int min_element = *std::min_element(_sp.begin(), _sp.end());
	int max_element = *std::max_element(_sp.begin(), _sp.end());

	// Return the difference
	return max_element - min_element;
}

