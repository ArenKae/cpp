/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:24 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:04:05 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "utils.h"

//	Default constructor
Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor called." << std::endl;
}

//	Copy Constructor
Cat::Cat(const Cat &src) : Animal(src), _brain(NULL)
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = src; // Calls the assignment operator overload
}

//	Assignment Operator
//	The brain data is newly allocated from the source's brain, ensuring a deep copy.
Cat& Cat::operator=(const Cat& src)
{
	std::cout << "Cat assignment operator called." << std::endl;
	if (this != &src) {
		this->_type = src._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain); }
	return *this;
}

//	Destructor
Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete this->_brain;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

void Cat::makeSound(void) const
{
	std::cout << GREEN "Meow" RESET << std::endl;
}

//	Setter function to change an idea and demonstrate deep copy.
void Cat::newIdea(int index, std::string idea)
{
	return this->_brain->changeIdea(index, idea);
}

//	Getter function to access an idea at a given brain index.
std::string Cat::getIdea(int index) const
{
	return this->_brain->printIdea(index);
}