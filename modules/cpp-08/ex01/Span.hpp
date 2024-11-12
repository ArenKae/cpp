/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:06 by acosi             #+#    #+#             */
/*   Updated: 2024/11/13 00:40:15 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "utils.h"

class Span
{
	public:
		// Default constructor #OrthodoxCanoncialForm
		Span(void);
		
		// Value constructor
		Span(unsigned int N);
		
		// Copy constructor #OrthodoxCanoncialForm
		Span(const Span &src);

		// Destructor #OrthodoxCanoncialForm
		~Span();

		// Overloaded assignment operator #OrthodoxCanoncialForm
		Span& operator=(const Span &src);

		// Member functions
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;

		// Function template to add a range of iterators to the Span
		template <typename iterator>
		void addRange(iterator begin, iterator end)
		{
			// Calculate the number of elements to add
			unsigned int numToAdd = std::distance(begin, end);
			
			// Check if there is enough space in the Span to add these elements
			if (_sp.size() + numToAdd > _size)
				throw std::out_of_range("Not enough space in Span to add the range.");
			// Insert the elements into the Span
			_sp.insert(_sp.end(), begin, end);
			std::cout << "Range successfully added. Span capacity: " << YELLOW << _sp.size()  << "/" << _size << RESET << std::endl;
		}

		// Custom nested exception class
		class SpanFullException : public std::exception {
			private:
				int _value;

			public:
			// Constructor that accepts a value as parameter and stores it
			SpanFullException(int num) : _value(num) {}

			// Override the what() method to return the value and an error message
			const char* what() const throw() {
			std::cout << "Value " << _value << " could not be added. ";
			return ""; } };

	private:
		/*	A std::vector is a good choice of container here because elements are stored 
		contiguously in memory, which means efficient access and iteration. */
		std::vector<int> _sp;
		unsigned int _size;
};


#endif