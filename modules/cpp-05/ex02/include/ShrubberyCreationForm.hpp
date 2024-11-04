/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 03:33:38 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 12:42:47 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public: 
		// Name Constructor
		ShrubberyCreationForm(const std::string &target);

		// Destructor
		~ShrubberyCreationForm();

		// Assignment Operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &src);

		// Member functions
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &exectuor) const;
		
	private:
		std::string _target;

		// Default Constructor
		ShrubberyCreationForm(void);

		// Copy Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
};

#endif