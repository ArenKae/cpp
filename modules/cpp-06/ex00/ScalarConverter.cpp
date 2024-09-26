/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 01:45:04 by acosi             #+#    #+#             */
/*   Updated: 2024/09/26 01:53:20 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"

static void print(std::string str)
{
	std::cout << GREEN << str << RESET << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	print(str);
}