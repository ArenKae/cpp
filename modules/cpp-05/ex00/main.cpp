/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/20 03:43:03 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "utils.h"

int main(void)
{
	try { // The "try" keword indicates that this block is subject to exception handling.
		Bureaucrat b1("Palpatine", 2);
		std::cout << BLUE << b1.getName() << RESET ", bureaucrat grade " GREEN << b1.getGrade() << RESET "." << std::endl; 
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // Throws GradeTooHighException
	/*	"catch" is the exception handler, taking as parameter
		an object of the same type of the expected exception. */
	} catch (std::exception &e) {
		// Calling the what() method to get the error from the exception
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	std::cout << "\n---------------------------------------------\n" << std::endl;
	
	try {
		Bureaucrat b2("Valorum", 151); // Throws GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	std::cout << "\n---------------------------------------------\n" << std::endl;
	
	try {
		Bureaucrat b3("Nute Gunray", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade(); // Throws GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	return 0;
}