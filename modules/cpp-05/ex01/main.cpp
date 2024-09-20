/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:23:49 by acosi             #+#    #+#             */
/*   Updated: 2024/09/20 04:37:05 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "utils.h"

int main(void)
{
	try {
		Form t1("Test form 1", 0, 150);
	} catch (Form::GradeTooHighException &e) { // Catch a specific exception
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}
	try {
		Form t2("Test form 2", 1, 151);
	} catch (Form::GradeTooLowException &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		Bureaucrat b1("Palpatine", 2);
		Form f1("RSA", 1, 150);
		std::cout << b1 << std::endl;
		std::cout << "Form name : " BLUE << f1.getName() << RESET "\n";
		std::cout << "From signed : " RED << f1.getSigned() << RESET "\n";
		std::cout << "Grade required to sign : " YELLOW << f1.getSignGrade() << RESET "\n";
		std::cout << "Grade required to execute : " YELLOW << f1.getExecGrade() << RESET << std::endl;
		f1.beSigned(b1);
	} catch (std::exception &e) { // Catch a generic exception
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}

	std::cout << "\n---------------------------------------------\n" << std::endl;

	try {
		Bureaucrat b2("Valorum", 8);
		Form f2("Treaty of Coruscant", 15, 150);
		std::cout << f2 << std::endl;
		f2.beSigned(b2);
		std::cout << f2 << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED "Error: " << e.what() << RESET << std::endl;}
	
	return 0;
}