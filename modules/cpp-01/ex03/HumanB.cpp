/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:28:28 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:17:34 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	//std::cout << this->_name << " is created" << std::endl;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	//std::cout << this->_name << " is destroyed" << std::endl;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " has no weapon! " << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& type)
{
	this->_weapon = &type;
}