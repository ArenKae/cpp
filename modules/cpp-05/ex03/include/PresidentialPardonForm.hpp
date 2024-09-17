/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:58:29 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 02:07:27 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTION_PARDON_FORM_HPP
#define PRESIDENTION_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public: 
		// Default Constructor
		PresidentialPardonForm(void);
	
		// Name Constructor
		PresidentialPardonForm(const std::string &target);

		// Copy Constructor
		PresidentialPardonForm(const PresidentialPardonForm &src);

		// Destructor
		~PresidentialPardonForm();

		// Assignment Operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm &src);

		// Member functions
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &exectuor) const;
		
	private:
		std::string _target;
};

#endif