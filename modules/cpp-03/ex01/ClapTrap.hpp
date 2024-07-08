/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:51 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 04:05:21 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		// Constructor
		ClapTrap(const std::string &name);

		// Copy Constructor
		ClapTrap(const ClapTrap &src);

		// Destructor
		~ClapTrap();

		// Assignment Operator
		ClapTrap& operator=(const ClapTrap &src);

		// Member functions
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		// Wrapper function overloads to check for invalid inputs
		void takeDamage(int amount);
		void beRepaired(int amount);

	protected: // Protected attributes are now visible only from an instance or a child of the class
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif