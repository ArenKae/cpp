/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:07:03 by acosi             #+#    #+#             */
/*   Updated: 2024/06/26 04:43:54 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main(int ac, char** av)
{
    if (ac =! 4)
    {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    if (!replace(av))
        return 0;
    return 1;
}

