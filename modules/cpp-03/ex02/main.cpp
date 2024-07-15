/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:22 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 13:03:10 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "utils.h"

int main(void)
{
	ClapTrap C3PO("C3-PO");
	ScavTrap R2D2("R2-D2");
	FragTrap BB8("BB-8");
	std::cout << std::endl;

	// ClapTrap tests
    std::cout << MAGENTA ">>> CLAPTRAP <<<" RESET << std::endl;
	C3PO.attack("Jawa");
	C3PO.takeDamage(5);
	C3PO.beRepaired(1);
	C3PO.takeDamage(6);
	std::cout << std::endl;

	// ScavTrap tests
    std::cout << MAGENTA ">>> SCAVTRAP <<<" RESET << std::endl;
	R2D2.getEnergy();
	R2D2.attack("Stormtrooper");
	R2D2.takeDamage(42);
	R2D2.beRepaired(20);
	R2D2.getEnergy();
	R2D2.guardGate();
	std::cout << std::endl;

	// FragTrap tests
    std::cout << MAGENTA ">>> FRAGTRAP <<<" RESET << std::endl;
	BB8.getEnergy();
	BB8.attack("Bantha");
	BB8.takeDamage(10);
	BB8.beRepaired(6);
	BB8.getEnergy();
	BB8.highFivesGuys();
	std::cout << std::endl;

	return 0;
}