/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:22 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 04:30:36 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap C3PO("C3-PO");
	ScavTrap R2D2("R2-D2");
	FragTrap BB8("BB-8");
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

	// FragTrap tests
	BB8.attack("Bantha");
	BB8.takeDamage(10);
	BB8.beRepaired(6);
	BB8.highFivesGuys();
	std::cout << std::endl;

	return 0;
}