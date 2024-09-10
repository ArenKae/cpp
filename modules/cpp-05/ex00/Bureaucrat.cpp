/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:36:13 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 08:31:59 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "utils.h"

// Default Constructor
Bureaucrat::Bureaucrat(void)
    : _name("Default name"), _grade(0)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

// Name constructor
Bureaucrat::Bureaucrat(const std::string &name)
    : _name(name), _grade(0)
{
    std::cout << "Bureaucrat constructor called for " << BLUE << _name << RESET << std::endl;
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
    if (this != &src) {
        this->_grade = src.getGrade();
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called for " << BLUE << _name << RESET << std::endl; 
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



