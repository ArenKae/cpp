/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:22 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 08:09:34 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap C3PO("C3-PO");
	ScavTrap R2D2("R2-D2");
	std::cout << std::endl;

	// ClapTrap tests
	C3PO.attack("Jawa");
	C3PO.takeDamage(5);
	C3PO.beRepaired(1);
	C3PO.takeDamage(6);
	std::cout << std::endl;

	// ScavTrap tests
	R2D2.attack("Stormtrooper");
	R2D2.takeDamage(42);
	R2D2.beRepaired(20);
	R2D2.guardGate();
	std::cout << std::endl;

	ScavTrap R4D4 = R2D2;
	R4D4.attack("Stormtrooper");
	R4D4.takeDamage(42);
	R4D4.beRepaired(20);
	R4D4.guardGate();
	std::cout << std::endl;

	return 0;
}