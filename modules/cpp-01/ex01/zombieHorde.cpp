/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:15:44 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:27:45 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    initZombies(Zombie &zombieHorde, int i, std::string name)
{
	zombieHorde.setIndex(i + 1);
	zombieHorde.setName(name);
	zombieHorde.announce();
}

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		initZombies(zombieHorde[i], i, name);}
	return zombieHorde;
}