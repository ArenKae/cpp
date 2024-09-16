/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:06 by acosi             #+#    #+#             */
/*   Updated: 2024/09/16 23:47:08 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "utils.h"

// Default Constructor
Form::Form(void)
	: _name("Default name"), _signed(false), _sign_grade(150), _exec_grade(1)
{
	std::cout << "Form default constructor called." << std::endl;
}

// Name constructor
Form::Form(const std::string &name, const int sign_grade, const int exec_grade)
	: _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form constructor called for " << BLUE << _name << RESET << std::endl;
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
Form::Form(const Form &src)
	: _name(src._name), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
	*this = src;
	std::cout << "Form copy constructor called for " << BLUE << _name << RESET << std::endl;
}

// Assignment Operator
Form& Form::operator=(const Form &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form destructor called for " << BLUE << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, Form const &rhs)
{
	output << "Form name: " << BLUE << rhs.getName() << RESET << std::endl;
	output << "Form signed: ";
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

std::string Form::getName(void) const
{
	return this->_name;
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getSignGrade(void) const
{
	return this->_sign_grade;
}

int Form::getExecGrade(void) const
{
	return this->_exec_grade;
}

int Form::beSigned(const Bureaucrat &src)
{
	if (src.getGrade() > this->getSignGrade()) {
		src.signForm(this->getSigned(), this->getName());
		throw Bureaucrat::GradeTooLowException();}
	else {
		this->_signed = true;
		src.signForm(this->getSigned(), this->getName());}
	return 0;
}

