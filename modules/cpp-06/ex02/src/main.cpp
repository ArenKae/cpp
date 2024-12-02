/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 03:30:55 by acosi             #+#    #+#             */
/*   Updated: 2024/12/02 08:15:38 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"
#include "../include/functions.hpp"

int main()
{
	std::cout << MAGENTA "[RANDOM INSTANCE TEST]" RESET << std::endl;
	Base *basePTR = generate();
	
	std::cout << "Identifying via pointer: ";
	identify(basePTR);

	std::cout << "Identifying via reference: ";
	identify(*basePTR);

	delete basePTR;

	std::cout << "\n" MAGENTA "[UNKOWN POINTER TEST]" RESET << std::endl;
	Base *newPTR = NULL;
	identify(newPTR);
	identify(*newPTR);
	
	return 0;
}