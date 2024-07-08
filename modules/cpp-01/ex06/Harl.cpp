/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:52:45 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 05:52:30 by acosi            ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void Harl::complain(std::string level)
{
	/*	Declare an array of member functions pointers "functionsPTR" with 4 elements.
		Each element is assigned the adress of a member function from the class Harold. */
	void (Harl::*functionsPTR[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	// An array of strings matching the levels of complain to compare with the function's argument.
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	// Index is set to the correct value matching the position of the log level in the string array
	int index = -1;
	for (int i = 0; i < 4; ++i)
	{
		if (level == levels[i])
			index = i;
	}
	
	// The value of index is evaluated and compared with different cases
	switch (index)
    	{
        	case 0:
				for (int i = 0; i < 4; i++)
            		(this->*functionsPTR[i])();
				break;
        	case 1:
				for (int i = 1; i < 4; i++)
            		(this->*functionsPTR[i])();
				break;
        	case 2:
				for (int i = 2; i < 4; i++)
            		(this->*functionsPTR[i])();
				break;
        	case 3:
            	(this->*functionsPTR[3])();
            	break;
        	default:
            	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            	break;
    }
}