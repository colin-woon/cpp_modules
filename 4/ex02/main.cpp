/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:11 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 15:47:44 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	// This won't compile - AAnimal is abstract:
	// AAnimal a;

	// These are fine - using concrete derived classes:
	const AAnimal *dog = new Dog();
	const AAnimal *cat = new Cat();

	dog->makeSound();
	cat->makeSound();

	// Test deep copy with Dog
	{
		Dog originalDog;
		Dog copyDog = originalDog; // Should create a deep copy

		std::cout << "Original Dog address: " << &originalDog << std::endl;
		std::cout << "Copy Dog address: " << &copyDog << std::endl;
	}

	// Clean up
	delete dog;
	delete cat;

	return 0;
}
