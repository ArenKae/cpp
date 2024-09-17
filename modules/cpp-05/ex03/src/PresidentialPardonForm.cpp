/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:58:26 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 02:15:50 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/utils.h"

// Default Constructor
PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("Default name", 25, 5), _target("default target")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

// Name constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called for " << GREEN << _name << RESET << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	: AForm(src), _target(src.getTarget())
{
	*this = src;
	std::cout << "PresidentialPardonForm copy constructor called for " << GREEN << _name << RESET << std::endl;
}

// Assignment Operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	//std::cout << "PresidentialPardonForm destructor called for " << GREEN << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, PresidentialPardonForm const &rhs)
{
	output << "PresidentialPardonForm name: " << BLUE << rhs.getName() << RESET << std::endl;
	output << "PresidentialPardonForm signed: ";
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

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &exectuor) const
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
		std::cout << YELLOW ">>> " << this->getTarget() << 
		" has been pardoned by Zaphod Beeblebrox." RESET << std::endl;}
}