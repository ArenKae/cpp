/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:31 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 09:45:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "utils.h"

// Default Constructor
ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGated = false;
}

// Name Constructor
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called for " << BLUE << _name <<  RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGated = false;
}

// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap()
{
	*this = src;
    std::cout << "ScavTrap copy constructor called for " BLUE << _name <<  RESET << std::endl;
}

// Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
    if (this != &src) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
		_isGated = src._isGated;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " BLUE << _name <<  RESET << std::endl;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Overridden attack function
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << BLUE << _name <<  RESET << " attacks " << RED 
		<< target <<  RESET << ", causing " << YELLOW << _attackDamage << RESET 
		<< " points of damage! The Maker would be proud!" << std::endl;
        _energyPoints -= 1; }
	else if (_energyPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough energy." << std::endl;
	else if (_hitPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough hit points." << std::endl;
}

// Special capacity
void ScavTrap::guardGate()
{
	if (this->_isGated == false) {
		std::cout << BLUE << _name << RESET << " is now in Gate keeper mode" << std::endl;
		this->_isGated = true;}
	else
		std::cout << BLUE << _name << RESET << " is already in Gate keeper mode" << std::endl;
}