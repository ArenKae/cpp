/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:20:49 by acosi             #+#    #+#             */
/*   Updated: 2024/06/27 04:09:14 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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