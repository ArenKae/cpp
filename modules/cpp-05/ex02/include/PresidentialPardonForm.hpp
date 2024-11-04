/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:58:29 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 12:43:50 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTION_PARDON_FORM_HPP
#define PRESIDENTION_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// Name Constructor
		PresidentialPardonForm(const std::string &target);

		// Destructor
		~PresidentialPardonForm();

		// Assignment Operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm &src);

		// Member functions
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &exectuor) const;
		
	private:
		std::string _target;

		// Default Constructor
		PresidentialPardonForm(void);

		// Copy Constructor
		PresidentialPardonForm(const PresidentialPardonForm &src);
};

#endif