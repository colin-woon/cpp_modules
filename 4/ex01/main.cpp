/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:11 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 22:38:32 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

// RAII (Resource Acquisition Is Initialization) mainly a c++ design principle
// that ensures resources are properly managed and released when they go out of scope.
// It is a programming idiom that binds the lifecycle of a resource to the lifetime of an object.

// In this case, the resource is the memory allocated for the Brain object.
// The Brain object is allocated in the constructor of the Dog class and is released in the destructor.

// DEEP COPY VS SHALLOW COPY
// Shallow Copy :
// - Copies the memory addresses of dynamically allocated objects instead of duplicating the actual content.
// - This leads to multiple objects sharing the same memory, which can cause issues like double deletion when one object goes out of scope and deallocates the shared memory.
// Default copy constructor and assignment operator perform a shallow copy.

// Deep Copy :
// - Allocates new memory and copies the actual contents of dynamically allocated objects, ensuring each object has its own independent copy.
// - Requires implementing a custom copy constructor and copy assignment operator to handle dynamic memory correctly.

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	// To trigger leak, remove the delete this->_brain command in the Dog or Cat destructors.
	delete j; // should not create a leak
	delete i;

	std::cout << "\n=== Creating Array of Animals ===" << std::endl;
	const int arraySize = 4;
	Animal *animals[arraySize];

	// Fill array with Dogs and Cats
	std::cout << "\n=== Creating Dogs ===" << std::endl;
	for (int i = 0; i < arraySize / 2; i++)
	{
		animals[i] = new Dog();
	}

	std::cout << "\n=== Creating Cats ===" << std::endl;
	for (int i = arraySize / 2; i < arraySize; i++)
	{
		animals[i] = new Cat();
	}

	// To trigger double deletion to prove deep and shallow copy, remove the delete _brain command in the Dog or Cat copy assignment operator.
	std::cout << "\n=== Testing Deep Copy for Dog ===" << std::endl;
	{
		Dog originalDog;
		Dog copyDog = originalDog; // Copy constructor

		// Verify they are different objects
		std::cout << "Original Dog address: " << &originalDog << std::endl;
		std::cout << "Copied Dog address: " << &copyDog << std::endl;

		// Both dogs should be destroyed here
	}

	std::cout << "\n=== Testing Deep Copy for Cat ===" << std::endl;
	{
		Cat originalCat;
		Cat copyCat(originalCat); // Copy constructor

		// Verify they are different objects
		std::cout << "Original Cat address: " << &originalCat << std::endl;
		std::cout << "Copied Cat address: " << &copyCat << std::endl;

		// Both cats should be destroyed here
	}

	std::cout << "\n=== Deleting Array of Animals ===" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		delete animals[i]; // Should call appropriate destructors
	}

	return 0;
}
