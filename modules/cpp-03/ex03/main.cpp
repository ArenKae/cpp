/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:22 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:00:51 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "utils.h"

int main(void)
{
	ScavTrap C3PO("C3-PO");
	FragTrap R2D2("R2D2");
	DiamondTrap HK47("HK-47");
	std::cout << std::endl;

	std::cout << MAGENTA ">>> SCAVTRAP <<<" RESET << std::endl;
	C3PO.getEnergy();
	C3PO.attack("Stormtrooper");
	C3PO.takeDamage(42);
	C3PO.beRepaired(20);
	C3PO.getEnergy();
	C3PO.guardGate();
	std::cout << std::endl;

	std::cout << MAGENTA ">>> FRAGTRAP <<<" RESET << std::endl;
	R2D2.attack("Bantha");
	R2D2.takeDamage(10);
	R2D2.beRepaired(6);
	R2D2.highFivesGuys();
	std::cout << std::endl;

	std::cout << MAGENTA ">>> DIAMONDTRAP <<<" RESET << std::endl;
	HK47.getEnergy();
	HK47.attack("Meatbag");
	HK47.takeDamage(10);
	HK47.beRepaired(6);
	HK47.getEnergy();
	HK47.guardGate();
	HK47.highFivesGuys();
	HK47.whoAmI();
	std::cout << std::endl;

	return 0;
}