/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:11 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:13:06 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "\n=== Basic Polymorphism Tests ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "Dog type: " << j->getType() << std::endl;
	std::cout << "Cat type: " << i->getType() << std::endl;
	std::cout << "Base type: " << meta->getType() << std::endl;

	std::cout << "\nTesting makeSound():" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n=== Copy Constructor Tests ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;

	Cat originalCat;
	Cat copiedCat(originalCat);
	std::cout << "Original Cat type: " << originalCat.getType() << std::endl;
	std::cout << "Copied Cat type: " << copiedCat.getType() << std::endl;

	std::cout << "\n=== Assignment Operator Tests ===" << std::endl;
	Dog assignedDog;
	assignedDog = originalDog;
	std::cout << "Assigned Dog type: " << assignedDog.getType() << std::endl;

	Cat assignedCat;
	assignedCat = originalCat;
	std::cout << "Assigned Cat type: " << assignedCat.getType() << std::endl;

	std::cout << "\n=== Type Constructor Tests ===" << std::endl;
	Dog customDog("CustomDog");
	Cat customCat("CustomCat");
	std::cout << "Custom Dog type: " << customDog.getType() << std::endl;
	std::cout << "Custom Cat type: " << customCat.getType() << std::endl;

	std::cout << "\n=== Array of Animals Test ===" << std::endl;
	Animal *animals[4];
	for (int k = 0; k < 2; k++)
	{
		animals[k] = new Dog();
	}
	for (int k = 2; k < 4; k++)
	{
		animals[k] = new Cat();
	}

	for (int k = 0; k < 4; k++)
	{
		std::cout << "Animal " << k << " type: " << animals[k]->getType() << std::endl;
		animals[k]->makeSound();
	}

	std::cout << "\n=== Cleanup ===" << std::endl;
	std::cout << "Deleting i, j and meta objects..." << std::endl
			  << std::endl;
	delete j;
	delete i;
	delete meta;

	std::cout << std::endl
			  << "Deleting animals array..." << std::endl
			  << std::endl;
	for (int k = 0; k < 4; k++)
	{
		delete animals[k];
	}
	std::cout << std::endl
			  << "Deleting others..." << std::endl
			  << std::endl;

	return 0;
}
