/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:06 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 02:10:24 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/utils.h"
#include <fstream>
#include <cstring>

// Default Constructor
ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Default name", 145, 137), _target("default target")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

// Name constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for " << GREEN << _name << RESET << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	: AForm(src), _target(src.getTarget())
{
	*this = src;
	std::cout << "ShrubberyCreationForm copy constructor called for " << GREEN << _name << RESET << std::endl;
}

// Assignment Operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	//std::cout << "ShrubberyCreationForm destructor called for " << GREEN << _name << RESET << std::endl; 
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, ShrubberyCreationForm const &rhs)
{
	output << "ShrubberyCreationForm name: " << BLUE << rhs.getName() << RESET << std::endl;
	output << "ShrubberyCreationForm signed: ";
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

std::string ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &exectuor) const
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
		std::ofstream file((getTarget() + "_shrubbery").c_str()); // Creating output file
		if (!file.is_open() || file.fail())	// Error handling
			{std::cerr <<  RED << "Error while creating file "  << RESET <<
			YELLOW << getTarget() + "_shrubbery" << RESET << std::endl;
			return ;}
		file << "\n"
				"              v .   ._, |_  .,\n"
				"           `-._\\/  .  \\ /    |/_\n"
				"               \\\\  _\\, y | \\//\n"
				"         _\\_.___\\\\, \\/ -\\.||\n"
				"           `7-,--.`._||  / / ,\n"
				"           /'     `-. `./ / |/_.\n"
				"                     |    |//\n"
				"                     |_    /\n"
				"                     |-   |\n"
				"                     |   =|\n"
				"                     |    |\n"
				"--------------------/ ,  . \\--------._";
		file.close();}
}