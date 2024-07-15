/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:09:14 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:30:43 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

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

		//	Pure virtual function, making AAnimal an abstract class that can't be instanciated.
		virtual void makeSound(void) const = 0;
};

#endif