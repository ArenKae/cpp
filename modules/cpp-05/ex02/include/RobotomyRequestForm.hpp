/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 01:21:20 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 12:44:07 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	public: 
		// Name Constructor
		RobotomyRequestForm(const std::string &target);

		// Destructor
		~RobotomyRequestForm();

		// Assignment Operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm &src);

		// Member functions
		std::string getTarget() const;
		virtual void execute(Bureaucrat const &exectuor) const;
		
	private:
		std::string _target;

		// Default Constructor
		RobotomyRequestForm(void);

		// Copy Constructor
		RobotomyRequestForm(const RobotomyRequestForm &src);
};

#endif