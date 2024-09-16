/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:03 by acosi             #+#    #+#             */
/*   Updated: 2024/09/16 22:51:32 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"


class AForm
{
	public:
		// Nested Exception Classes
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form grade too high";}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form grade too low";}
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form not signed";}
		};

		// Default Constructor
		AForm(void);
	
		// Name Constructor
		AForm(const std::string &name, const int sign_grade, const int exec_grade);

		// Copy Constructor
		AForm(const AForm &src);

		// Destructor
		// A virtual destructor ensures leak-safe ressource cleaning of derived classes.
		virtual ~AForm();

		// Assignment Operator
		AForm& operator=(const AForm &src);

		// Member functions
		std::string getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		int beSigned(const Bureaucrat &src);

		//	Pure virtual function, making AForm an abstract class that can't be instanciated.
		virtual int execute(Bureaucrat const &exectuor) const = 0;

	protected:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
};

// Stream redirection (insertion: <<) operator overload :
std::ostream& operator<<(std::ostream &output, AForm const &rhs);

#endif