/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 23:12:02 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 16:17:02 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "utils.h"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << MAGENTA << ">>> SUBJECT TESTS <<<" << RESET << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl << std::endl;
	
	std::cout << MAGENTA << ">>> PERSONAL TESTS <<<" << RESET << std::endl;
	Fixed c(Fixed(42) / Fixed(7));
	std::cout << "c = (42 / 7) = " << c << std::endl;
	std::cout << "--c = " << --c << std::endl;
	std::cout << "++c = " << ++c << std::endl;
	std::cout << "b = " << b << std::endl;
	Fixed d(c+b);
	std::cout << "d = c + b = " << d << std::endl;
	Fixed a1(0.1016f); // roundf() by the float constructor
	std::cout << "a1 = " << a1 << std::endl; // Recast as a float by the stream redirection operator overload
	std::cout << "d - a1 = " << d - a1 << std::endl << std::endl;
	std::cout << "max(a,b) = max(" << a << "," << b << ") = " << Fixed::max(a,b) << std::endl;
	std::cout << "min(c,d) = min(" << c << "," << d << ") = " << Fixed::min(c,d) << std::endl << std::endl;
	std::cout << GREEN << "1 = TRUE" << RED << "  0 = FALSE" << RESET << std::endl;
	std::cout << "a(" << a << ") est plus grand que b(" << b << ") : " << RED << (a > b) << RESET << std::endl;
	std::cout << "c(" << c << ") est plus petit que d(" << d << ") : " << GREEN << (c < d) << RESET << std::endl;
	return 0;
}