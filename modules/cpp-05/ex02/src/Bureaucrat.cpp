/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:36:13 by acosi             #+#    #+#             */
/*   Updated: 2024/09/20 07:25:26 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/utils.h"

// Default Constructor
Bureaucrat::Bureaucrat(void)
	: _name("Default name"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called." << std::endl;
}

// Name constructor
Bureaucrat::Bureaucrat(const std::string &name,int grade)
	: _name(name), _grade(grade)
{
	//std::cout << "Bureaucrat constructor called for " << BLUE << _name << RESET << std::endl;
	if (grade < 1)
		throw GradeTooHighException(); // "throw" keyword is used to signal an exception
	if (grade > 150)
		throw GradeTooLowException();
}

// Copy Constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
	std::cout << "Bureaucrat copy constructor called for " << BLUE << _name << RESET << std::endl;
}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat destructor called for " << BLUE << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, Bureaucrat const &rhs)
{
	output << BLUE << rhs.getName() << RESET ", bureaucrat grade " GREEN << rhs.getGrade() << RESET ".";
	return output;
}

/* ****************	*/
/* MEMBER FUNCTIONS	*/
/* ****************	*/

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

//  Prints an appropriate message when a bureaucrat attempts to sign a form.
int Bureaucrat::signForm(const bool _signed, const std::string form) const
{
	if (_signed == false) {
		std::cout << BLUE << this->getName() << RESET " couldn't sign form " GREEN << form 
		<< RESET " because " RED "GradeTooLowException" RESET << std::endl;
		return 1;}
	else
		std::cout << BLUE << this->getName() << RESET " signed " GREEN << form << RESET << std::endl;
	return 0;
}

// Attempts to execute the form and prints an appropriate message.
void Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
	std::cout << BLUE << this->getName() << RESET " executed " GREEN << form.getName() << RESET << std::endl;
}