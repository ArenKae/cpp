/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:21:20 by acosi             #+#    #+#             */
/*   Updated: 2024/09/17 01:22:22 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public: 
		// Default Constructor
		RobotomyRequestForm(void);
	
		// Name Constructor
		RobotomyRequestForm(const std::string &target);

		// Copy Constructor
		RobotomyRequestForm(const RobotomyRequestForm &src);

		// Destructor
		~RobotomyRequestForm();

		// Assignment Operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm &src);

		// Member functions
		std::string getTarget() const;
		virtual int execute(Bureaucrat const &exectuor) const;
		
	private:
		std::string _target;
};

#endif