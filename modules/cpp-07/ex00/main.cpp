/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:59:35 by acosi             #+#    #+#             */
/*   Updated: 2024/11/03 16:06:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "utils.h"
#include <iostream>

int main(void)
{
	{
		int a = 2;
		int b = 3;

		std::cout << MAGENTA "[SUBJECT TESTS]" RESET << std::endl;
		::swap(a,b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min(a,b) = " << ::min(a,b) << std::endl;
		std::cout << "max(a,b) = " << ::max(a,b) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c,d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min(c,d) = " << ::min(c,d) << std::endl;
		std::cout << "max(c,d) = " << ::max(c,d) << std::endl;
	}
	{
		float a = -42;
		float b = 0.42;

		std::cout << MAGENTA "\n[FLOAT TESTS]" RESET << std::endl;
		::swap(a,b);
		std::cout << "a = " GREEN << a << RESET ", b = " CYAN << b << std::endl;
		std::cout << RESET "min(a,b) = " CYAN << ::min(a,b) << std::endl;
		std::cout << RESET "max(a,b) = " GREEN << ::max(a,b) << std::endl;
	}
	{
		char a = 'z';
		char b = 'a';

		std::cout << MAGENTA "\n[CHAR TESTS]" RESET << std::endl;
		::swap(a,b);
		std::cout << "a = " GREEN << a << RESET ", b = " CYAN << b << std::endl;
		std::cout << RESET "min(a,b) = " CYAN << ::min(a,b) << std::endl;
		std::cout << RESET "max(a,b) = " GREEN << ::max(a,b) << std::endl;
	}
	return 0;
}