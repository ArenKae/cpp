/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/20 07:19:56 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/utils.h"

int main(void)
{
	/* Seeds the random generator with the current time for the RobotomyRequestForm.
	   Seeding is necessary to get a different number every time the program runs.
	   The seeding is done in the main function so that it only happens once, allowing
	   the std::rand() function to get a different number with each call. */
	std::srand(std::time(0));
	
	try {
		std::cout << MAGENTA "[GRADE OUT OF BOUNDS TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 189);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		std::cout << MAGENTA "[BUREAUCRAT GRADE TOO LOW TO SIGN TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 147);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		std::cout << MAGENTA "[FORM NOT SIGNED TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 2);
		ShrubberyCreationForm f1("home");
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		std::cout << MAGENTA "[BUREAUCRAT GRADE TOO LOW TO EXECUTE TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 139);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
		std::cout << f1 << std::endl;
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		std::cout << MAGENTA "[SHRUBBERY CREATION OK TEST]" RESET << std::endl;
		Bureaucrat b1("Palpatine", 50);
		ShrubberyCreationForm f1("home");
		f1.beSigned(b1);
		b1.executeForm(f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;
	
	try {
		std::cout << MAGENTA "[ROBOTOMY REQUEST OK TEST]" RESET << std::endl;
		Bureaucrat b2("Sidious", 45);
		RobotomyRequestForm f2("Vador");
		f2.beSigned(b2);
		f2.execute(b2);
		b2.executeForm(f2);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		std::cout << MAGENTA "[PRESIDENTIAL PARDON OK TEST]" RESET << std::endl;
		Bureaucrat b3("Valorum", 4);
		PresidentialPardonForm f3("Nute Gunray");
		f3.beSigned(b3);
		b3.executeForm(f3);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << '\n' << std::endl;}

	return 0;
}