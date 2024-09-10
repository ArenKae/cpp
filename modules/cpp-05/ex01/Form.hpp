/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:03 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 10:39:06 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class Form
{
	public:
		// Nested Exception Classes
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too high";}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return "Grade too low";}
		};

		// Default Constructor
		Form(void);
	
		// Name Constructor
		Form(const std::string &name, int grade);

		// Copy Constructor
		Form(const Form &src);

		// Destructor
		~Form();

		// Assignment Operator
		Form& operator=(const Form &src);

		// Member functions
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade();
		void beSigned(const Bureaucrat &src);

	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
};

// Stream redirection (insertion: <<) operator overload :
std::ostream& operator<<(std::ostream &output, Form const &rhs);

#endif