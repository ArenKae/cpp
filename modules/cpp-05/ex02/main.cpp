/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 00:53:04 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.h"

int main(void)
{
	try {
		std::cout << MAGENTA "[GRADE OUT OF BOUNDS TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 189);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}
	
	try {
		std::cout << MAGENTA "[BUREAUCRAT GRADE TOO LOW TO SIGN TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 147);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}
	
	try {
		std::cout << MAGENTA "[FORM NOT SIGNED TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 2);
		ShrubberyCreationForm f1("home");
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}

	try {
		std::cout << MAGENTA "[BUREAUCRAT GRADE TOO LOW TO EXECUTE TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 139);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}

	try {
		std::cout << MAGENTA "[SHRUBBERY CREATION OK TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 50);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}

	std::cout << "---------------------------------------------" << std::endl;

	

	return 0;
}