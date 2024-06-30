/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:52:45 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 22:59:52 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	//std::cout << "Harl constructor called." << std::endl;
}

Harl::~Harl(void)
{
	//std::cout << "Harl destructor called." << std::endl;
}

void Harl::debug(void)
{
	std::cout << BLUE <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" 
	<< RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN <<
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << YELLOW <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << RED <<
	"This is unacceptable! I want to speak to the manager now." << std::endl
	<< RESET << std::endl;
}

void Harl::complain(std::string level)
{
	/*	Declare an array of member functions pointers "functionsPTR" with 4 elements.
		Each element is assigned the adress of a member function from the class Harold. */
	void (Harl::*functionsPTR[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	// An array of strings matching the levels of complain to compare with the function's argument.
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i]) {
			(this->*functionsPTR[i])();	// The current instance of Harl calls the matching function through *functionPTR
			return ; }
	}
	std::cout  << "UNKNOWN LEVEL: Harl doesn't have any comments for this level." << std::endl;
}
