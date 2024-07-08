/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 00:11:09 by acosi             #+#    #+#             */
/*   Updated: 2024/07/08 04:25:04 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap // Inheritance from ClapTrap
{
	public:
		// Constructor
		FragTrap(const std::string &name);

		// Copy Constructor
		FragTrap(const FragTrap &src);

		// Destructor
		~FragTrap();

		// Assignment Operator
		FragTrap& operator=(const FragTrap &src);

		// Special member function
		void highFivesGuys(void);
};

#endif