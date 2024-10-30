/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:37:35 by acosi             #+#    #+#             */
/*   Updated: 2024/10/30 21:31:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/functions.hpp"

// Generate a random instance of type A, B or C.
Base *generate(void)
{
	// Seed the random number generator based on the current time
	std::srand(std::time(0));

	int rand = std::rand() % 3;
	
	switch (rand)
	{
		case 0:
			std::cout << "Generated instance of type " YELLOW "A" RESET << std::endl;
			return new A;
		case 1:
			std::cout << "Generated instance of type " YELLOW "B" RESET << std::endl;
			return new B;
		case 2:
			std::cout << "Generated instance of type " YELLOW "C" RESET << std::endl;
			return new C;
	}
	return NULL;
}

// Identify instance real type from a pointer.
void identify(Base *p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << YELLOW "A" RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << YELLOW "B" RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << YELLOW "C" RESET << std::endl;
	else
		std::cout << RED "Error: unknown pointer type" RESET << std::endl;
}

// Identify instance real type from a reference.
void identify(Base &p)
{
	bool flag = false;
	
	try 
	{
		dynamic_cast<A&>(p);
		flag = true;
		std::cout << YELLOW "A" RESET << std::endl;
	}
	catch (std::exception &e) {}

	if (flag == false)
	{
		try
		{
			dynamic_cast<B&>(p);
			flag = true;
			std::cout << YELLOW "B" RESET << std::endl;
		}
		catch (std::exception &e) {}
	}
	
	if (flag == false)
	{
		try 
		{
			dynamic_cast<C&>(p);
			flag = true;
			std::cout << YELLOW "C" RESET << std::endl;
		}
		catch (std::exception &e) {}
	}

	if (flag == false)
		std::cout << RED "Error: unknown pointer type" RESET << std::endl;
}