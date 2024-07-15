/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:51 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:02:08 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		// Name Constructor
		ClapTrap(const std::string &name);

		// Copy Constructor
		ClapTrap(const ClapTrap &src);

		// Assignment Operator
		ClapTrap& operator=(const ClapTrap &src);

		/*	Destructor
		A virtual destructor ensures proper cleanup of derived class objects
		when they are deleted through a pointer of the base class. Otherwise,
		only the derived class destructor is called and this might cause
		undefined behavior and ressource leaks. Virtual makes sure that every
		destructors from the top are called. */
		virtual ~ClapTrap();

		/*	Member functions
		A virtual member function can be overriden by functions of the same name
		to achieve runtime polymorphism. This ensures that the correct function
		implementation is called based on the actual type of the object. */
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getEnergy(void);

		// Wrapper function overloads to check for invalid inputs
		void takeDamage(int amount);
		void beRepaired(int amount);

	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

		// Default constructor to meet canonical orthodox form requirements
		ClapTrap(void);	
};

#endif