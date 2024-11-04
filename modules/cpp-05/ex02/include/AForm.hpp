/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:28:03 by acosi             #+#    #+#             */
/*   Updated: 2024/11/04 12:40:07 by acosi            ###   ########.fr       */
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
					return "Form Grade Too High Exception";}
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form Grade Too Low Exception";}
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw() {
					return "Form Not Signed Exception";}
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
		virtual void execute(Bureaucrat const &exectuor) const = 0;

	protected:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exec_grade;
};

// Stream redirection (insertion: <<) operator overload :
std::ostream& operator<<(std::ostream &output, AForm const &rhs);

#endif