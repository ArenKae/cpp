/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/18 03:24:21 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include "../include/utils.h"

int main(void)
{
	try {
		std::cout << MAGENTA "[INVALID FORM NAME TEST]" RESET << std::endl;
        Bureaucrat b1; Intern i1; AForm *f1;
        (void)f1;
		f1 = i1.makeForm("homework", "home");
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}

	try {
		std::cout << MAGENTA "[GRADE TOO LOW TEST]" RESET << std::endl;
        Bureaucrat b1; Intern i1; AForm *f1;
		f1 = i1.makeForm("shrubbery creation", "home");
        f1->beSigned(b1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}

	try {
		std::cout << MAGENTA "[FORM NOT SIGNED TEST]" RESET << std::endl;
        Bureaucrat b1("Palpatine", 2); Intern i1; AForm *f1;
		f1 = i1.makeForm("shrubbery creation", "home");
        b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}

    try {
		std::cout << MAGENTA "[SHRUBBERY CREATION OK TEST]" RESET << std::endl;
        Bureaucrat b1("Palpatine", 2); Intern i1; AForm *f1;
		f1 = i1.makeForm("shrubbery creation", "home");
        f1->beSigned(b1);
        b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}

    std::cout << "---------------------------------------------" << std::endl;

    try {
		std::cout << MAGENTA "[ROBOTOMY REQUEST OK TEST]" RESET << std::endl;
        Bureaucrat b1("Palpatine", 2); Intern i1; AForm *f1;
		f1 = i1.makeForm("robotomy request", "Vador");
        f1->beSigned(b1);
        b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}

    std::cout << "---------------------------------------------" << std::endl;

    try {
		std::cout << MAGENTA "[PRESIDENTIAL PARDON OK TEST]" RESET << std::endl;
        Bureaucrat b1("Palpatine", 2); Intern i1; AForm *f1;
		f1 = i1.makeForm("presidential pardon", "Nute Gunray");
        f1->beSigned(b1);
        b1.executeForm(*f1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	return 0;
}