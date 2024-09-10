/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 10:03:00 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "utils.h"

int main(void)
{
	try {
		Bureaucrat b1("Palpatine", 2);
		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.incrementGrade(); // Throws GradeTooHighException
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
		std::cout << std::endl;

	try {
		Bureaucrat b2("Valorum", 151); // Throws GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }
		std::cout << std::endl;
	
	try {
		Bureaucrat b3("Nute Gunray", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade(); // Throws GradeTooLowException
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl; }

	return 0;
}