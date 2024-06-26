/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:38:07 by acosi             #+#    #+#             */
/*   Updated: 2024/06/26 04:38:21 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int    replace(char **av)
{
    std::ifstream input_file(av[1], std::ifstream::in);
    if (!input_file)
    {
        std::cerr << "Error while opening : " << av[1] << std::endl;
        return (1);
    }
    std::string    new_file = av[1];
    new_file.append(".replace");
    std::ofstream output_file(new_file.c_str(), std::ofstream::out);
    if (!output_file)
    {
        std::cerr << "Error while creating file : " << new_file << std::endl;
        return (1);
    }
    std::string buffer;
    int    pos = 0;
    std::getline(input_file, buffer, '\0');
    if (strlen(av[2]) > 0)
    {
        while ((pos = buffer.find(av[2])) != -1)
        {
            buffer.erase(pos, strlen(av[2]));
            buffer.insert(pos, av[3]);
        }
    }
    output_file << buffer;
    input_file.close();
    output_file.close();
    return (0);
}