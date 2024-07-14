/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acosi <acosi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 08:07:50 by acosi             #+#    #+#             */
/*   Updated: 2024/07/15 00:14:39 by acosi            ###   ########.fr       */
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
		std::cout << MAGENTA << ">>> TESTING DEEP COPIES <<<" << RESET << std::endl;
		Dog originalDog;
		Dog copyDog(originalDog);
		originalDog.makeSound();
		copyDog.makeSound();
		
		Cat originalCat;
		Cat copyCat(originalCat);
		originalCat.makeSound();
		copyCat.makeSound();
	}
	return 0;
}