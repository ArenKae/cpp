/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:31 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 04:13:04 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.h"

// Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called for " << BLUE << _name <<  RESET << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor called for " << BLUE << _name <<  RESET << std::endl;
}

// Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src)
		ClapTrap::operator=(src);
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << BLUE << _name <<  RESET << std::endl;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Overridden attack method
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << BLUE << _name <<  RESET << " attacks " << RED 
		<< target <<  RESET << ", causing " << YELLOW << _attackDamage << RESET 
		<< " points of damage! Master Ani would be proud!" << std::endl;
        _energyPoints -= 1; }
	else if (_energyPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough energy." << std::endl;
	else if (_hitPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough hit points." << std::endl;
}

// Special capacity
void ScavTrap::guardGate()
{
	std::cout << BLUE << _name << RESET << " is now in Gate keeper mode" << std::endl;
}