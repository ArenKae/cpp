/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 05:11:36 by acosi            ###   ########.fr       */
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
		std::cout << MAGENTA "[INVALID FORM NAME TEST]" RESET << std::endl;
		Intern i1;
		//AForm *f1;
		//f1 = i1.makeForm("homework", "home");
		//std::cout << b1 << std::endl;
		//f1->beSigned(b1);
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << "\n" << std::endl;}
	return 0;
}