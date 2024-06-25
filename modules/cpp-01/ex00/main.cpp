/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:20:49 by acosi             #+#    #+#             */
/*   Updated: 2024/06/25 23:01:31 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	// Creates a zombie on the heap
	Zombie* JohnyHeap = newZombie("JohnyHeap");
	JohnyHeap->announce();

	// Create a zombie on the stack
	randomChump("JackStack");
	
	// Deletes the heap allocated zombie
	delete JohnyHeap;
	
	return 0;
}