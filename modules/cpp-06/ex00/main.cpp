/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 03:30:55 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 08:42:58 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "utils.h"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << RED << "Usage: ./convert <literal>" << RESET << std::endl;
        return 1;
    }	
    ScalarConverter::convert(av[1]);
    return 0;
}