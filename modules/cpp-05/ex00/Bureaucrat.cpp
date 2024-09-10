/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:36:13 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 07:50:10 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default Constructor
Bureaucrat::Bureaucrat(void)
    : _name("Default name"), _grade(0)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

