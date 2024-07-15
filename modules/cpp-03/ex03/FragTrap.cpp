/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:31 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:22:29 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "utils.h"

// Default Constructor
FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Name Constructor
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called for " << BLUE << _name <<  RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

// Copy Constructor
FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	*this = src;
    std::cout << "FragTrap copy constructor called for " << BLUE << _name <<  RESET << std::endl;
}

// Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& src)
{
    if (this != &src) {
        this->_name = src._name;
        this->_hitPoints = src._hitPoints;
        this->_energyPoints = src._energyPoints;
        this->_attackDamage = src._attackDamage;
    }
    return *this;
}

// Destructor
FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << BLUE << _name <<  RESET << std::endl;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

// Special capacity
void FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << _name << RESET << " wants to high fives, don't keep him waiting!" << std::endl;
}