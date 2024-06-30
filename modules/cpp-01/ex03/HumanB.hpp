/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:20:23 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 23:10:23 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
		std::string _name;
        Weapon* _weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
        void attack();
        void setWeapon(Weapon& type);

};

#endif