/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:45:32 by acosi             #+#    #+#             */
/*   Updated: 2024/07/14 19:03:35 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANIMAL_HPP
#define WANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		~WrongAnimal(void); // Not virtual to demonstrate that the derived class destructor is not called
		WrongAnimal& operator=(const WrongAnimal &src);

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif