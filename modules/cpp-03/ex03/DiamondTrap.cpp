/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 07:03:14 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:38:42 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "utils.h"

// Default Constructor
DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	this->_hitPoints = FragTrap_HP;
	this->_energyPoints = ScavTrap_EP;
	this->_attackDamage = FragTrap_AD;
}

// Name Constructor
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	std::cout << "DiamondTrap constructor called for " BLUE << _name << RESET << std::endl;
	this->_hitPoints = FragTrap_HP;
	this->_energyPoints = ScavTrap_EP;
	this->_attackDamage = FragTrap_AD;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(), FragTrap(), ScavTrap()
{
	*this = src;
    std::cout << "DiamondTrap copy constructor called for " BLUE << _name <<  RESET << std::endl;
}

// Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
    if (this != &src) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " BLUE << _name <<  RESET << std::endl;
}

// Special capacity
void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " BLUE << _name 
	<< RESET " and my ClapTrap name is " BLUE << ClapTrap::_name 
	<< RESET << std::endl;
}