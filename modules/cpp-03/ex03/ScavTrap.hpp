/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:09 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 09:12:46 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/*	Virtual inheritance is used to solve the "diamond problem".
	If class A has two derived classes B and C, and D is dervied from both B and C,
	this means that 2 sub-objects A will be instanciated when creating D.
	It can lead to ambiguity when accessing A members and must be resloved with
	virtual inheritance. With this method, only one instance of A is shared among
	all derived classes.
*/

class ScavTrap : virtual public ClapTrap // Virtual inheritance from ClapTrap
{
	public:
		// Name Constructor
		ScavTrap(const std::string &name);

		// Copy Constructor
		ScavTrap(const ScavTrap &src);

		// Destructor
		~ScavTrap();

		// Assignment Operator
		ScavTrap& operator=(const ScavTrap &src);

		// Member functions
		void attack(const std::string &target); // Overridden attack method
		void guardGate();

	private:
		bool _isGated; // Used to store Gate mode status

	protected:
		// Default constructor to meet canonical orthodox form requirements
		ScavTrap(void);	
};

#endif