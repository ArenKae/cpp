/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 02:28:52 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 13:43:47 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/utils.h"

// Default Constructor
Intern::Intern(void) : _form(NULL)
{
	std::cout << "Intern constructor called." << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern &src) : _form(src._form)
{
	*this = src;
	std::cout << "Intern copy constructor called." << std::endl;
}

// Assignment Operator
Intern& Intern::operator=(const Intern &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Intern destructor called." << std::endl;
	if (_form)
		delete _form;
}

//	Stream redirection (insertion: <<) operator overload
std::ostream& operator<<(std::ostream &output, Intern const &rhs)
{
    (void)rhs;
	return output;
}

/*   -----FUNCTIONS-----   */

AForm* createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
    // Array of valid form names
    std::string formName[3] = 
		{"shrubbery creation", "robotomy request", "presidential pardon"};

    // Array of function pointers for creating forms
    AForm* (*formArray[3])(const std::string &target) = 
		{&createShrubbery, &createRobotomy, &createPresidential};

    // Iterate over the form names to find the correct one
    for (int i = 0; i < 3; ++i) {
        if (formName[i] == name) {
            std::cout << "Intern creates " << GREEN << name << RESET << std::endl;
			_form = formArray[i](target); // Call the corresponding form creation function
            return _form; // Returns a pointer to the Form for easier memory management.
        }
    }
	// Exception for error handling with invalid form name
	throw (Intern::InvalidFormName());
}