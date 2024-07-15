/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 23:50:00 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 01:13:55 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		//	Default Constructor
		Brain(void);
		
		//	Copy Constructor
		Brain(const Brain &src);

		//	Destructor
		~Brain(void);
		
		//	Assignment operator
		Brain& operator=(const Brain &src);

		// Member functions :
		void changeIdea(int index, std::string idea);
		std::string printIdea(int index) const;
};

#endif