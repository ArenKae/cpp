/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:37 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:01:54 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;
	public:
		Dog(void);
		Dog(const Dog &src);
		~Dog(void);
		Dog& operator=(const Dog &src);

		virtual void makeSound(void) const;
		void newIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif