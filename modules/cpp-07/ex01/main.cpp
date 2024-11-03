/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:59:35 by acosi             #+#    #+#             */
/*   Updated: 2024/11/03 17:23:16 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "utils.h"

void capitalizeChar(char &c)
{
	c = std::toupper(c);
};

void capitalizeStr(std::string &str)
{
	for (std::string::iterator i = str.begin(); i != str.end(); i++)
		*i = std::toupper(*i);
};

void	appendSuffix(std::string &str)
{
	str += "_S";
}

int main(void)
{
	{
		int tab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		size_t size = 10;
		
		std::cout << MAGENTA "[INT ARRAY TESTS]" RESET << std::endl;
		::iter(tab, size, ::printElement<int>);

		std::cout << YELLOW "\nIncrementing array :" RESET << std::endl;
		::iter(tab, size, ::incrementElement<int>);
		::iter(tab, size, ::printElement<int>);

		std::cout << YELLOW "\n42-fying array :" RESET << std::endl;
		::iter(tab, size, ::to_42<int>);
		::iter(tab, size, ::printElement<int>);
		std::cout << "\n" << std::endl;
	}
	{
		char tab[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		size_t size = 10;
		
		std::cout << MAGENTA "[CHAR ARRAY TESTS]" RESET << std::endl;
		::iter(tab, size, ::printElement<char>);

		std::cout << YELLOW "\nIncrementing array :" RESET << std::endl;
		::iter(tab, size, ::incrementElement<char>);
		::iter(tab, size, ::printElement<char>);

		std::cout << YELLOW "\nCapitalizing array :" RESET << std::endl;
		::iter(tab, size, capitalizeChar);
		::iter(tab, size, ::printElement<char>);

		std::cout << YELLOW "\n42-fying array :" RESET << std::endl;
		::iter(tab, size, ::to_42<char>);
		::iter(tab, size, ::printElement<char>);
		std::cout << "\n" << std::endl;
	}
	{
		std::string tab[] = {"I", "am", "your", "father"};
		size_t size = 4;
		
		std::cout << MAGENTA "[STRING ARRAY TESTS]" RESET << std::endl;
		::iter(tab, size, ::printElement<std::string>);;

		std::cout << YELLOW "\nCapitalizing array :" RESET << std::endl;
		::iter(tab, size, capitalizeStr);
		::iter(tab, size, ::printElement<std::string>);

		std::cout << YELLOW "\nAdding suffix to array :" RESET << std::endl;
		::iter(tab, size, appendSuffix);
		::iter(tab, size, ::printElement<std::string>);

		std::cout << YELLOW "\n42-fying array :" RESET << std::endl;
		::iter(tab, size, ::to_42<std::string>);
		::iter(tab, size, ::printElement<std::string>);
		std::cout << std::endl;
	}
	return 0;
}