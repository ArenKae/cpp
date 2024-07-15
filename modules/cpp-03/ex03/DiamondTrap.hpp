/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:48:40 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:28:56 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap // Inherits from both classes
{
	private:
		std::string _name;

	public:
		// Name Constructor
		DiamondTrap(const std::string &name);

		// Copy Constructor
		DiamondTrap(const DiamondTrap &src);

		// Destructor
		~DiamondTrap(void);

		// Assignment Operator
		DiamondTrap& operator=(const DiamondTrap &src);

		// Member function
		using ScavTrap::attack;
		void whoAmI();

	protected:
		// Default constructor to meet canonical orthodox form requirements
		DiamondTrap(void);	
};

#endif