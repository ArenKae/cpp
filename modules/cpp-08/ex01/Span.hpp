/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:24:06 by acosi             #+#    #+#             */
/*   Updated: 2024/11/07 11:32:11 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span
{
	public:
		// Default constructor #OrthodoxCanoncialForm
		Span(void);
		
		// Value constructor
		Span(unsigned int &N);
		
		// Copy constructor #OrthodoxCanoncialForm
		Span(const Span &src);

		// Destructor #OrthodoxCanoncialForm
		~Span();

		// Overloaded assignment operator #OrthodoxCanoncialForm
		Span& operator=(const Span &src);

		// Member functions
		void addNumber();
	private:
		
};


#endif