/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:09 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 03:29:03 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>


class ScavTrap : public ClapTrap // Inheritance from ClapTrap
{
	public:
		// Constructor
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
};

#endif