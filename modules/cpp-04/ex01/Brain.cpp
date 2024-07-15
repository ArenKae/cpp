/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:53:53 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:03:30 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Default constructor
Brain::Brain(void)
{
	std::cout << "Brain constructor called." << std::endl;
	// Initialize the ideas array
	// Iterates the array, converts the index into a string and concatenates it with the "Idea "
	for (int i = 0; i < 100; ++i) {
		std::stringstream ss;
		ss << "Idea " << i;
		this->_ideas[i] = ss.str(); 
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

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Setter function to change an idea and demonstrate deep copy.
void Brain::changeIdea(int index, std::string idea)
{
	this->_ideas[index] = idea;
}

//	Getter function to access an idea in a given brain index.
std::string Brain::printIdea(int index) const
{
	return this->_ideas[index];
}