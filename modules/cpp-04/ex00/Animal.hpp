/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:09:14 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 08:43:43 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;

	public:
		// Default constructor
		Animal(void);
		
		// Copy constructor
		Animal(const Animal &src);

		// Destructor
		~Animal(void);
		
		// Assignment operator
		Animal& operator=(const Animal &src);

		// Member functions :
		virtual void makeSound();
		void getType();
};

#endif