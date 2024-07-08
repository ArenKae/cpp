/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:47:24 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 10:17:03 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int megaphone(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		// Skip leading spaces
		int start = 0;
		while (av[i][start] && std::isspace(av[i][start]))
			++start;

		// Find the end of the argument while ignoring trailing spaces
		int end = std::strlen(av[i]) - 1;
		while (end >= start && std::isspace(av[i][end]))
			--end;

		// Print each character converting to uppercase, preserving all spaces in between
		for (int j = start; j <= end; ++j)
		{
			std::cout << (char)std::toupper(av[i][j]);
		}

		// Print a space between arguments
		if (i < ac - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}

int main(int ac, char **av)
{
	if (ac >= 2)
		return megaphone(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return 0;
}