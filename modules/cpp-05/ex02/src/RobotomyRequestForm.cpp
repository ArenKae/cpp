/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:21:24 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 01:52:14 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/utils.h"
#include <cstdlib>
#include <ctime>

// Default Constructor
RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Default name", 72, 45), _target("default target")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

// Name constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target + "_shrubbery", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called for " << GREEN << _name << RESET << std::endl;
}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm(src), _target(src.getTarget())
{
	*this = src;
	std::cout << "RobotomyRequestForm copy constructor called for " << GREEN << _name << RESET << std::endl;
}

// Assignment Operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	//std::cout << "RobotomyRequestForm destructor called for " << GREEN << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, RobotomyRequestForm const &rhs)
{
	output << "RobotomyRequestForm name: " << BLUE << rhs.getName() << RESET << std::endl;
	output << "RobotomyRequestForm signed: ";
	if (rhs.getSigned())
		output << GREEN << "true" << RESET << std::endl;
	else
		output << RED << "false" << RESET << std::endl;
	output << "Grade required to sign: " << YELLOW << rhs.getSignGrade() << RESET << std::endl;
	output << "Grade required to execute: " << YELLOW << rhs.getExecGrade() << RESET;
	return output;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

int RobotomyRequestForm::execute(Bureaucrat const &exectuor) const
{
	std::string str;

	// Checks that the form is signed
	if (this->getSigned() == false) {
		str = "FormNotSignedException";
		std::cout << BLUE << exectuor.getName() << RESET " couldn't execute form " GREEN << 
		this->getName() << RESET " because " RED << str << RESET << std::endl;
		throw AForm::FormNotSignedException();}

	// Checks that the bureaucrat has sufficient grade to execute
	else if (exectuor.getGrade() > this->getExecGrade()) {
		str = "BureaucratGradeTooLowException";
		std::cout << BLUE << exectuor.getName() << RESET " couldn't execute form " GREEN << 
		this->getName() << RESET " because " RED << str << RESET << std::endl;
		throw Bureaucrat::GradeTooLowException();}

	// Execute the form
	else {
		std::cout << YELLOW ">>> * Drilling noises *" << std::endl;
		// Seeds the random generator with the current time to ensure a different number each time the program runs.
		std::srand(std::time(0));
    	if (std::rand() % 2 == 0) {
        std::cout << ">>> " << this->getTarget() << " has been robotomized successfully!" RESET << std::endl;
    	} else {
        std::cout << ">>> The robotomy failed." RESET << std::endl;}
	}
	return EXIT_SUCCESS;
}