/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:09:14 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 19:20:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;

	public:
		//	Default constructor
		Animal(void);

		//	Type initialization constructor
		Animal(std::string type);
		
		//	Copy constructor
		Animal(const Animal &src);

		/*	Destructor
			The virtual keyword ensures proper cleanup of derived class objects
			when they are deleted through a pointer of the base class. Otherwise,
			only the derived class destructor is called and this might cause
			undefined behavior and ressource leaks. Virtual makes sure that every
			destructors from the top are called. */
		virtual ~Animal(void);
		
		//	Assignment operator
		Animal& operator=(const Animal &src);

		//	Member functions :
		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif