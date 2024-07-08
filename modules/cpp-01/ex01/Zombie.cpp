/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:08:51 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:27:33 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	//std::cout << this->name << " constructor called." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << "[" << this->index << "]" << " destructor called." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << "[" << this->index << "]" << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setIndex(int i)
{
	this->index = i;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}