/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 04:49:33 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include "../include/utils.h"

int main(void)
{
	try {
		std::cout << MAGENTA "[INTERN TEST]" RESET << std::endl;
		Bureaucrat b3("Valorum", 4);
		Intern i1;
		AForm *form;
		form = i1.makeForm("presidyential pardon", "Nute Gunray");
		form->beSigned(b3);
		b3.executeForm(*form);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}
	return 0;
}