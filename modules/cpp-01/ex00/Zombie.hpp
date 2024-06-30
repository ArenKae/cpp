/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:02:24 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 23:11:12 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string str);
		~Zombie(void);
		void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif