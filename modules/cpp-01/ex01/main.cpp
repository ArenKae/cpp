/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 23:04:28 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 13:27:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie * Horde = zombieHorde(10, "Toto");

	// Additionnal tests
	std::cout << std::endl;
	Horde->announce(); // First element of the Horde
	Horde[3].announce(); // Another element of the Horde
	std::cout << std::endl;
	
	delete [] Horde;
	return 0;
}