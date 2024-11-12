/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:06 by acosi             #+#    #+#             */
/*   Updated: 2024/11/12 19:07:40 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

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
			return "SpanFullException"; } };

	private:
		std::vector<int> lst;
		unsigned int _size;
};


#endif