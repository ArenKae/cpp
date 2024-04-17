#include <iostream>
#include <string.h>

int    megaphone(int ac, char **av)
{
    int i = 1;
    int j = 0;
    while(av[i])
    {
        while (isspace(av[i][j])) // Skip leading spaces
            j++;
        while (av[i][j])
        {
            std::cout << (char)toupper(av[i][j]), j++; // Convert to uppercase and print to stdout
            if (isspace(av[i][j]) && (isspace(av[i][j + 1]) || !av[i][j + 1]))
                while(av[i][j] && isspace(av[i][j]))
                    j++; // Skip spaces at the end of a word
        }
        i++, j = 0;
        if (i < ac)
            std::cout << ' '; // Print a space between arguments
    }
    std::cout << std::endl; // Newline and flush
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