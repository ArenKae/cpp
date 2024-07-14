/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:53:53 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:27:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


// Default constructor
Brain::Brain(void)
{
	std::cout << "Brain constructor called." << std::endl;
	// Iterates the array, converts the index into a string and concatenates it with the "Idea "
	for (int i; i < 100; ++i) {
		std::stringstream ss;
		ss << "Idea " << i;
		_ideas[i] = ss.str(); 
	}
}

// Copy Constructor
Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = src;
}

// Assignment Operator
Brain& Brain::operator=(const Brain& src)
{
	if (this != &src) {
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = src._ideas[i]; }
	return *this;
}

// Destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}