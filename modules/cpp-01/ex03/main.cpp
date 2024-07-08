/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:11:26 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:26:30 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
		
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("other type of club");
	bob.attack();

	std::cout << std::endl;

	Weapon axe = Weapon("iron axe");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(axe);
	jim.attack();
	axe.setType("other type of axe");
	jim.attack();
	
	return 0;
}