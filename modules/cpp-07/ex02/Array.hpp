/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 12:24:07 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 10:34:00 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>
#include "utils.h"

template<typename T>
class Array
{
	public:
		// Default constructor : Creates an empty Array
		Array(void) : _size(0), _elements(NULL) {}

		// Size constructor : Creates an Array of n elements of type T
		Array(unsigned int n) : _size(n), _elements(new T[n]()) {}

		// Copy constructor
		Array(const Array &src) : _size(src._size), _elements(new T[src._size])
		{
			for (unsigned int i = 0; i < this->_size; ++i)
				this->_elements[i] = src._elements[i];
		}

		// Destructor
		~Array() {delete [] this->_elements;}
		
		// Overloaded assignment operator (=)
		Array& operator=(const Array &src)
		{
			if (this != src) {
				delete [] this->_elements;
				this->_size = src._size;
				this->_elements = new T[_size];
				for (unsigned int i = 0; i < _size; ++i)
					this->elements[i] = src.elements[i];
			}
			return *this;
		}

		// Overloade subscript operator ([])
		T& operator[](unsigned int index)
		{
			if (index > _size)
				throw std::out_of_range("Index out of bounds");
			return _elements[index];
		}

		// Member functions

		
		unsigned int size() const {return _size;}

		const T& getElement(unsigned int index) const {return _elements[index];}
		
		void printSize(const std::string &name) const
		{std::cout << "Size of " CYAN << name << RESET ": " GREEN << _size << RESET << std::endl;}
		

	private:
		unsigned int _size;
		T* _elements;
};

//	Overloaded stream redirection operator (<<)
template <typename U>
std::ostream& operator<<(std::ostream& output, const Array<U>& array)
{
    for (unsigned int i = 0; i < array.size(); ++i)
        output << GREEN << array.getElement(i) << RESET " ";
    return output;
}

#endif