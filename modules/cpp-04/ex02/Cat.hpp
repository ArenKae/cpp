/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:52:28 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:28:04 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat(void);
		Cat(const Cat &src);
		~Cat(void);
		Cat& operator=(const Cat &src);

		virtual void makeSound(void) const;
		void newIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif