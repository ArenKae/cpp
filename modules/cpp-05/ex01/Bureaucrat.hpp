/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:36:16 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 10:14:05 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
	public:
		/*	Nested Exception Classes
			Inherit from the exception class from std namespace, allowing them to 
			be caught by a catch {} block and behave like standard exceptions.
			The what() method from std::exception returns a C-string and is
			overridden to return a custom error message.
			
		*/
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
		Bureaucrat(void);
	
		// Name Constructor
		Bureaucrat(const std::string &name, int grade);

		// Copy Constructor
		Bureaucrat(const Bureaucrat &src);

		// Destructor
		~Bureaucrat();

		// Assignment Operator
		Bureaucrat& operator=(const Bureaucrat &src);

		

		// Member functions
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

	private:
		const std::string _name;
		int _grade;
};

// Stream redirection (insertion: <<) operator overload :
std::ostream& operator<<(std::ostream &output, Bureaucrat const &rhs);

#endif