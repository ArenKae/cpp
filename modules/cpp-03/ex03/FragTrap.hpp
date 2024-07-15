/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:09 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 10:30:13 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#define FragTrap_HP 100
#define FragTrap_EP 100
#define FragTrap_AD 30


/*	Virtual inheritance is used to solve the "diamond problem".
	If class A has two derived classes B and C, and D is dervied from both B and C,
	this means that 2 sub-objects A will be instanciated when creating D.
	It can lead to ambiguity when accessing A members and must be resloved with
	virtual inheritance. With this method, only one instance of A is shared among
	all derived classes.
*/

class FragTrap : virtual public ClapTrap // Virtual inheritance from ClapTrap
{
	public:
		// Name Constructor
		FragTrap(const std::string &name);

		// Copy Constructor
		FragTrap(const FragTrap &src);

		// Destructor
		~FragTrap();

		// Assignment Operator
		FragTrap& operator=(const FragTrap &src);

		// Special member function
		void highFivesGuys(void);
	
	protected:
		// Default constructor to meet canonical orthodox form requirements
		FragTrap(void);	
};

#endif