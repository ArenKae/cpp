/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:51 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 07:41:54 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

class ClapTrap
{
	public:
		// Name Constructor
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

	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
		
		// Default constructor to meet canonical orthodox form requirements
		ClapTrap(void);	

};

#endif