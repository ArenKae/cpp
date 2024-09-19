/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtassel <dtassel@42.nice.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 08:03:36 by dtassel           #+#    #+#             */
/*   Updated: 2024/01/22 10:32:31 by dtassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input;
        input = av[1];
        if (input == "")
        {
            std::cerr << "Error : Arg is empty" << std::endl;
            return -1;
        }
        ScalarConverter::convert(input);
        return (0);
    }
    std::cerr << "Error : Need 2 arguments" << std::endl;
    return -1;
}