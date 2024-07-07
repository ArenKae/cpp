/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:41:43 by acosi             #+#    #+#             */
/*   Updated: 2024/07/07 19:23:11 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.h"

// Constructor
ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called for " << BLUE << _name <<  RESET << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &src)
    : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
    std::cout << "ClapTrap copy constructor called for " << BLUE << _name <<  RESET << std::endl;
}

// Assignment Operator
ClapTrap& ClapTrap::operator=(const ClapTrap& src)
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
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << BLUE << _name <<  RESET << std::endl;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Attack
void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        std::cout << "ClapTrap " << BLUE << _name <<  RESET << " attacks " << RED 
		<< target <<  RESET << ", causing " << YELLOW << _attackDamage << RESET 
		<< " points of damage!" << std::endl;
        _energyPoints -= 1; }
	else if (_energyPoints <= 0)
        std::cout << "ClapTrap " << BLUE << _name << RESET << " can't attack : not enough energy." << std::endl;
	else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << BLUE << _name << RESET << " can't attack : not enough hit points." << std::endl;
}

// Take Damage
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << RED << "ClapTrap " << _name << " is already down !" << RESET << std::endl;
		return; }
    _hitPoints -= amount;
    if (_hitPoints < 0) {
    	_hitPoints = 0; }
	std::cout << "ClapTrap " << BLUE << _name <<  RESET << " takes " 
	<< RED << amount <<  RESET << " points of damage!";
	if (_hitPoints == 0) {
		std::cout << " Current hit points: " << YELLOW << _hitPoints << std::endl;
		std::cout << RED << "ClapTrap " << _name << " is down !" << RESET << std::endl; }
	else
		std::cout << " Current hit points: " << GREEN << _hitPoints << RESET <<std::endl;
}

// Be Repaired
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0) {
        _hitPoints += amount;
        std::cout << "ClapTrap " << BLUE << _name << RESET << " is repaired by " 
		<< YELLOW << amount << RESET << " points! Current hit points: " << GREEN 
		<< _hitPoints << RESET << std::endl;
        _energyPoints -= 1; }
    else if (_energyPoints <= 0)
        std::cout << "ClapTrap " << BLUE << _name << RESET << " can't be repaired. Not enough energy points." << std::endl;
    else if (_hitPoints <= 0)
        std::cout << "ClapTrap " << BLUE << _name << RESET << " can't be repaired. Not enough hit points." << std::endl;
}