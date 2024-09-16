/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:06 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 01:07:12 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include "../include/utils.h"

// Default Constructor
AForm::AForm(void)
	: _name("Default name"), _signed(false), _sign_grade(1), _exec_grade(1)
{
	std::cout << "AForm default constructor called." << std::endl;
}

// Name constructor
AForm::AForm(const std::string &name, const int sign_grade, const int exec_grade)
	: _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm constructor called for " << GREEN << _name << RESET << std::endl;
	if (_sign_grade < 1)
		throw GradeTooHighException(); // "throw" keyword is used to signal an exception
	if (_sign_grade > 150)
		throw GradeTooLowException();
	if (_exec_grade < 1)
		throw GradeTooHighException();
	if (_exec_grade > 150)
		throw GradeTooLowException();
}

// Copy Constructor
AForm::AForm(const AForm &src)
	: _name(src._name), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	*this = src;
	std::cout << "AForm copy constructor called for " << GREEN << _name << RESET << std::endl;
}

// Assignment Operator
AForm& AForm::operator=(const AForm &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
AForm::~AForm()
{
	//std::cout << "AForm destructor called for " << GREEN << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, AForm const &rhs)
{
	output << "AForm name: " << BLUE << rhs.getName() << RESET << std::endl;
	output << "AForm signed: ";
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

std::string AForm::getName(void) const
{
	return this->_name;
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getSignGrade(void) const
{
	return this->_sign_grade;
}

int AForm::getExecGrade(void) const
{
	return this->_exec_grade;
}

//  Attemtps to sign the form and prints an appropriate message or exception.
int AForm::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() > this->getSignGrade()) {
		src.signForm(this->getSigned(), this->getName());
		throw Bureaucrat::GradeTooLowException();}
	else {
		this->_signed = true;
		src.signForm(this->getSigned(), this->getName());}
	return 0;
}

