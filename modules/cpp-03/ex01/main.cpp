/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:40:22 by acosi             #+#    #+#             */
/*   Updated: 2024/07/07 23:13:39 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap R2D2("R2-D2");
	ClapTrap C3PO("C3-PO");
	std::cout << std::endl;

	// Basic tests
	R2D2.attack("Jawa");
	R2D2.takeDamage(5);
	R2D2.beRepaired(1);
	R2D2.takeDamage(6);
	std::cout << std::endl;

	// Attacking 10 times to empty energy
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");
	C3PO.attack("Jawa");

	// Test when no energy
	std::cout << std::endl;
	C3PO.beRepaired(1);
	C3PO.attack("Jawa");

	// Test when no hp
	std::cout << std::endl;
	R2D2.beRepaired(1);
	R2D2.attack("Jawa");
	R2D2.takeDamage(1);

	std::cout << std::endl;
	return 0;
}