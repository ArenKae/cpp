/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:36:16 by acosi             #+#    #+#             */
/*   Updated: 2024/09/10 08:31:19 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
	public:
		// Default Constructor
		Bureaucrat(void);
	
		// Name Constructor
		Bureaucrat(const std::string &name);

		// Copy Constructor
		Bureaucrat(const Bureaucrat &src);

		// Destructor
		~Bureaucrat();

		// Assignment Operator
		Bureaucrat& operator=(const Bureaucrat &src);

		// Member functions
		std::string getName() const;
		int getGrade() const;

	private:
		const std::string _name;
		int _grade;
};

#endif