/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:33 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:04:09 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "utils.h"

//	Default constructor
Dog::Dog(void) : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor called." << std::endl;
}

//	Copy Constructor
Dog::Dog(const Dog &src) : Animal(src), _brain(NULL)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = src; // Calls the assignment operator overload
}

//	Assignment Operator
//	The brain data is newly allocated from the source's brain, ensuring a deep copy.
Dog& Dog::operator=(const Dog& src)
{
	std::cout << "Dog assignment operator called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain); }
	return *this;
}

//	Destructor
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete this->_brain;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

void Dog::makeSound(void) const
{
	std::cout << BLUE "Woof" RESET << std::endl;
}

//	Setter function to change an idea and demonstrate deep copy.
void Dog::newIdea(int index, std::string idea)
{
	return this->_brain->changeIdea(index, idea);
}

//	Getter function to access an idea at a given brain index.
std::string Dog::getIdea(int index) const
{
	return this->_brain->printIdea(index);
}