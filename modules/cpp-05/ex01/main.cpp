/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/16 23:47:19 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.h"

int main(void)
{
	try { // The "try" keword indicates that this block is subject to exception handling.
		Bureaucrat b1("Palpatine", 2);
		Form f1("RSA", 1, 150);

		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;
		f1.beSigned(b1); // Throws GradeTooLowException	
	} catch (std::exception &e) {
		// Calling the what() method to get the error from the exception
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		std::cout << std::endl;}
	
	try {
		Bureaucrat b2("Valorum", 8);
		Form f2("Treaty of Coruscant", 15, 150);
		f2.beSigned(b2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;
		std::cout << std::endl;}
	
	return 0;
}