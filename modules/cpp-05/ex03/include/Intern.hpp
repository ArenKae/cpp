/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 02:28:56 by acosi             #+#    #+#             */
/*   Updated: 2024/09/18 03:03:09 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "../include/AForm.hpp"

class Intern
{
	public: 

		class InvalidFormName : public std::exception {
			public:
				const char *what() const throw() {
                    return "Invalid Form Name";}
		};

		// Default Constructor
		Intern(void);

		// Copy Constructor
		Intern(const Intern &src);

		// Destructor
		~Intern();

		// Assignment Operator
		Intern& operator=(const Intern &src);

		// Member functions
		AForm* makeForm(const std::string name, const std::string target) const;
};

#endif