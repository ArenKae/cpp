/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:41:43 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 08:50:02 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "utils.h"

// Default constructor
ClapTrap::ClapTrap(void)
	: _name("Default name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called for " BLUE << _name <<  RESET << std::endl;
}

// Name Constructor
ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called for " BLUE << _name <<  RESET << std::endl;
}

// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
    std::cout << "ClapTrap copy constructor called for " BLUE << _name <<  RESET << std::endl;
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
        std::cout << BLUE << _name <<  RESET << " attacks " << RED 
		<< target <<  RESET  << ", causing " << YELLOW << _attackDamage << RESET 
		<< " points of damage! This is not the droid you are looking for..." << std::endl;
        _energyPoints -= 1; }
	else if (_energyPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough energy." << std::endl;
	else if (_hitPoints <= 0)
        std::cout << BLUE << _name << RESET << " can't attack : not enough hit points." << std::endl;
}

// Take Damage
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << RED << _name << " is already down!" << RESET << std::endl;
		return; }
	_hitPoints -= amount;
	if (_hitPoints < 0) {
		_hitPoints = 0; }
	std::cout << BLUE << _name <<  RESET << " takes " 
	<< RED << amount <<  RESET << " points of damage!";
	if (_hitPoints == 0) {
		std::cout << " Current hit points: " << YELLOW << _hitPoints << std::endl;
		std::cout << RED << _name << " is down!" << RESET << std::endl; }
	else
		std::cout << " Current hit points: " << GREEN << _hitPoints << RESET <<std::endl;
}

// Wrapper function overloading the takeDamage() method to check for invalid inputs
void ClapTrap::takeDamage(int amount)
{
	
	if (amount < 0) {
		std::cerr << RED << "Error: Negative value provided for damage amount." << RESET << std::endl;
		return; }

	// The static_cast operator is used to perform an explicit and type-safe conversion
	takeDamage(static_cast<unsigned int>(amount));
}

// Be Repaired
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0) {
		_hitPoints += amount;
		std::cout << BLUE << _name << RESET << " is repaired by " 
		<< YELLOW << amount << RESET << " points! Current hit points: " << GREEN 
		<< _hitPoints << RESET << std::endl;
		_energyPoints -= 1; }
	else if (_energyPoints <= 0)
		std::cout << BLUE << _name << RESET << " can't be repaired. Not enough energy points." << std::endl;
	else if (_hitPoints <= 0)
		std::cout << BLUE << _name << RESET << " can't be repaired. Not enough hit points." << std::endl;
}

// Wrapper function overloading the beRepaired() method to check for invalid inputs
void ClapTrap::beRepaired(int amount)
{
	
	if (amount < 0) {
		std::cerr << RED << "Error: Negative value provided for repair amount." << RESET << std::endl;
		return; }

	// The static_cast operator is used to perform an explicit and type-safe conversion
	beRepaired(static_cast<unsigned int>(amount));
}

// Getter function to check the energy points.
void ClapTrap::getEnergy(void)
{
	if (_energyPoints > 0) {
		std::cout << BLUE << _name << RESET << " has " GREEN << _energyPoints 
		<< RESET << " energy points left." << std::endl; }
	else if (_energyPoints <= 0) {
		std::cout << BLUE << _name << RESET << " has no energy points left." << std::endl; }
}