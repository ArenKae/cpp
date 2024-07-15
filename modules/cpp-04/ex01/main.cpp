/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:07:50 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 02:16:35 by acosi            ###   ########.fr       */
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
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl;
		delete j;
		delete i;
		std::cout << std::endl;
	}
	{
		std::cout << MAGENTA << ">>> ADDITIONAL TESTS <<<" << RESET << std::endl;
		const int numAnimals = 6;
		Animal* animals[numAnimals]; // Creating an array of 6 animals

		for (int i = 0; i < numAnimals / 2; ++i) {
			animals[i] = new Dog();
		}
		for (int i = numAnimals / 2; i < numAnimals; ++i) {
			animals[i] = new Cat();
		}
		std::cout << std::endl;
		for (int i = 0; i < numAnimals; ++i) {
			animals[i]->makeSound();
		}
		std::cout << std::endl;
		for (int i = 0; i < numAnimals; ++i) {
			delete animals[i];
		}
		std::cout << std::endl;
	}
	{
		std::cout << MAGENTA << ">>> TESTING DEEP COPIES (CAT) <<<" << RESET << std::endl;
		// Creating a cat and its copy
		Cat originalCat;
		Cat copyCat(originalCat);
		// Checking what they think
		std::cout << "OriginalCat: " << RED << originalCat.getIdea(0) << RESET << std::endl;
		std::cout << "CopyCat: " << CYAN << copyCat.getIdea(0) << RESET << std::endl;
		// Changing OriginalCat's idea and checking that it doesn't affect the deep copy
		originalCat.newIdea(0, "I need to break something ฅ^._.^ฅ");
		std::cout << "OriginalCat: " << RED << originalCat.getIdea(0) << RESET << std::endl;
		std::cout << "CopyCat: " << CYAN << copyCat.getIdea(0) << RESET << std::endl;
	}
	/*{
		std::cout << MAGENTA << "\n>>> TESTING DEEP COPIES (DOG) <<<" << RESET << std::endl;
		// Creating a dog and its copy
		Dog originalDog;
		Dog copyDog(originalDog);
		// Checking what they think
		std::cout << "OriginalDog: " << GREEN << originalDog.getIdea(0) << RESET << std::endl;
		std::cout << "CopyDog: " << CYAN << copyDog.getIdea(0) << RESET << std::endl;
		// Changing OriginalCat's idea and checking that it doesn't affect the deep copy
		originalDog.newIdea(0, "I'm a good boy (❍ᴥ❍ʋ)");
		std::cout << "OriginalDog: " << GREEN << originalDog.getIdea(0) << RESET << std::endl;
		std::cout << "CopyDog: " << CYAN << copyDog.getIdea(0) << RESET << std::endl;
	}*/
	return 0;
}