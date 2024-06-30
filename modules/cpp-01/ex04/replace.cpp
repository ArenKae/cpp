/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 04:38:07 by acosi             #+#    #+#             */
/*   Updated: 2024/06/30 04:41:01 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"
#include "utils.hpp"

int    replace(char **av)
{
	/*	std::ifstream (input file stream) is a class from the C++ Standard Library used to read data from files.
		We create an instance "input_file" and pass the file to open  as argument to the constructor.
		By default, the file is open in read-only mode (std::ifstream::in) but this argument can be changed.
		The constructor automatically calls the method open() but we could also do it explicitely with :
		input_file.open(av[1]);	*/

    std::ifstream input_file(av[1]);
    if (!input_file.is_open() || input_file.fail())		// Error handling
		return print_error(av[1], OPEN);

	/*	Creating a string holding the name of the outpout file with the ".replace" extension. */

    std::string    filename = av[1];
    filename.append(".replace");

	/*	The std::string is converted to a C string with the method c_str() from the header <cstring>.
		This is necessary because open() expects a const char* just like av[1]. */
		
	const char* new_file = filename.c_str();

	/*	std::ofstream (output file stream) is a class used to write data in files. Again, an instance is
		created and we pass the name of the file to open as an argument to the constructor.
		By default, the opening mode is set to write (std::ofstream::out). */

    std::ofstream output_file(new_file);
    if (!output_file.is_open() || output_file.fail())	// Error handling
		return print_error(new_file, CREATE);
	
	// getline() reads from "input_file" and stores its content inside "buffer" until a '\0' is found (eof).
	std::string buffer;
	std::getline(input_file, buffer, '\0');
	
	size_t    pos = 0;
    if (strlen(av[2]) > 0)	// If the string to find av[2] is not empty
    {
		/*	find() returns the position of the string av[2] if it exists inside "buffer".
			If the string could not be found, it returns std::string::npos (often equals to -1).
			This value is then assigned to pos. */
        while ((pos = buffer.find(av[2])) != std::string::npos)
        {
			// If a match is found, erease strlen(av[2]) characters at the current position.
            buffer.erase(pos, strlen(av[2]));
			// Then, insert the replacement string av[3] at the current position.
            buffer.insert(pos, av[3]);
        }
    }
	
	// The modified content of buffer is written in the output_file.
    output_file << buffer;
	
	// All open file descriptors are closed 
    input_file.close();
    output_file.close();
    return (EXIT_SUCCESS);
}