/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:10:56 by acosi             #+#    #+#             */
/*   Updated: 2024/06/25 20:20:37 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string str) : name(str)
{
	//std::cout << this->name << " constructor called." << std::endl;
	this->name = str;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " destructor called." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": : BraiiiiiiinnnzzzZ..." << std::endl;
}

// Mutator to assign Zombie name (private) when newZombie() is called.
// void Zombie::setName(std::string name)
// {
// 	this->name = name;
// }
