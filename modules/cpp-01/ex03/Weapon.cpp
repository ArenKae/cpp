/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:28:28 by acosi             #+#    #+#             */
/*   Updated: 2024/06/26 03:36:59 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType) : type(newType)
{
	//std::cout << "The <" << this->type << "> weapon is created" << std::endl;
}

Weapon::~Weapon()
{
	//std::cout << "The <" << this->type << "> weapon is destroyed" << std::endl;
}

const std::string& Weapon::getType()
{
    return this->type;
}

void Weapon::setType(std::string NewType)
{
    this->type = NewType;    
}