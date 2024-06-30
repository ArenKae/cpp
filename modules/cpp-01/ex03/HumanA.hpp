/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 01:20:23 by acosi             #+#    #+#             */
/*   Updated: 2024/07/01 01:05:43 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
        void attack();
    private:
		std::string _name;
        Weapon& _weapon;
};

#endif