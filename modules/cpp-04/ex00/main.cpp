/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:07:50 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 13:36:13 by acosi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "utils.h"

int main(void) {
{
	std::cout << MAGENTA << ">>> SUBJECT TESTS <<<" << RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	// We can safely delete the objects of polymorphic classes 
	// because the destructor of the base class "Animal" is virtual.
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
}
{
        std::cout << MAGENTA << ">>> ADDITIONAL TESTS <<<" << RESET << std::endl;
        const WrongAnimal* metaWrong = new WrongAnimal();
        const WrongAnimal* k = new WrongCat();
        WrongCat kk;
		std::cout << std::endl;
        
		std::cout << metaWrong->getType() << std::endl;
        std::cout << k->getType() << std::endl;
        k->makeSound();				// Will output the wrong animal sound, not the cat sound,
        metaWrong->makeSound();		// because the function is not virtual
        kk.makeSound();
		std::cout << std::endl;

        delete metaWrong;
        delete k;
}
	return 0;
}