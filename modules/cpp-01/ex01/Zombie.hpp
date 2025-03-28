/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:05:37 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:27:39 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setIndex(int i);
		void setName(std::string name);
	private:
		int index;
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);
void    initZombies(Zombie& zombie, int N, std::string name);

#endif