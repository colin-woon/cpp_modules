/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:16:58 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 23:38:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

// int main()
// {
// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	ICharacter *me = new Character("me");
// 	AMateria *tmp;

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	ICharacter *bob = new Character("bob");
// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return 0;
// }

int main()
{
	// Test 1: Basic functionality (original test)
	std::cout << "\n=== Test 1: Basic Functionality ===\n";
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");
	AMateria *tmp;

	me->equip(NULL); // Should handle null
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	// Test 2: Edge cases for MateriaSource
	std::cout << "\n=== Test 2: MateriaSource Edge Cases ===\n";
	src->learnMateria(new Ice());		 // Third materia
	src->learnMateria(new Cure());		 // Fourth materia
	src->learnMateria(new Ice());		 // Should fail (full)
	src->learnMateria(NULL);			 // Should handle null
	tmp = src->createMateria("unknown"); // Should return NULL
	if (!tmp)
		std::cout << "Successfully handled unknown materia type\n";

	// Test 3: Character inventory limits
	std::cout << "\n=== Test 3: Character Inventory Limits ===\n";
	tmp = src->createMateria("ice");
	me->equip(tmp); // Third slot
	tmp = src->createMateria("cure");
	me->equip(tmp); // Fourth slot
	tmp = src->createMateria("ice");
	me->equip(tmp); // Should fail (full inventory)
	delete tmp;		// Clean up unequipped materia

	// Test 4: Unequip and floor management
	std::cout << "\n=== Test 4: Unequip Functionality ===\n";
	me->unequip(0);	 // Should work
	me->unequip(0);	 // Should fail (already empty)
	me->unequip(-1); // Should fail (invalid index)
	me->unequip(4);	 // Should fail (invalid index)

	// Test 5: Deep copy test
	std::cout << "\n=== Test 5: Deep Copy Test ===\n";
	Character *clone = new Character(*(Character *)me);
	clone->use(1, *bob); // Should work
	delete clone;

	// Test 6: Use edge cases
	std::cout << "\n=== Test 6: Use Edge Cases ===\n";
	me->use(-1, *bob); // Should fail
	me->use(4, *bob);  // Should fail
	me->use(0, *bob);  // Should fail (unequipped slot)

	// Test 7: Floor Management and Static Floor Array
	std::cout << "\n=== Test 7: Floor Management Stress Test ===\n";

	// Clear existing inventory first
	for (int i = 0; i < 4; i++)
	{
		me->unequip(i);
	}

	// Fill character inventory
	for (int i = 0; i < 4; i++)
	{
		tmp = src->createMateria("ice");
		if (tmp)
		{
			me->equip(tmp);
		}
	}

	// Test maximum unequips
	std::cout << "Testing maximum unequips...\n";
	for (int i = 0; i < 4; i++)
	{
		me->unequip(i); // Should add to floor
	}

	// Create new character to test floor interaction
	std::cout << "\nTesting floor interaction with new character...\n";
	ICharacter *alice = new Character("alice");

	tmp = src->createMateria("ice");
	if (tmp)
	{
		alice->equip(tmp);
	}

	tmp = src->createMateria("cure");
	if (tmp)
	{
		alice->equip(tmp);
	}

	// Use equipped materias to verify functionality
	alice->use(0, *bob);
	alice->use(1, *bob);

	// Test 8: Floor Array Limits with proper cleanup
	std::cout << "\n=== Test 8: Floor Array Limits ===\n";
	// Try to exceed floor array capacity
	for (int i = 0; i < 100; i++)
	{
		std::cout << "\nIteration " << i << ":\n";
		tmp = src->createMateria("ice");
		if (tmp)
		{
			// Simply test equip and unequip without checking inventory
			me->equip(tmp);
			me->unequip(0); // This will handle the floor management
		}
	}

	// Clean up in reverse order of creation
	delete alice;
	delete bob;
	delete me;

	std::cout << "\n=== Test 9: Last Character Cleanup Demonstration ===\n";

	// Create multiple characters that will share floor materias
	Character *char1 = new Character("First");
	Character *char2 = new Character("Second");
	Character *char3 = new Character("Last");

	// Create some materias and place on floor
	AMateria *m1 = src->createMateria("ice");
	AMateria *m2 = src->createMateria("cure");
	AMateria *m3 = src->createMateria("ice");

	// Equip and unequip to place materias on floor
	char1->equip(m1);
	char1->unequip(0); // m1 goes to floor
	char2->equip(m2);
	char2->unequip(0); // m2 goes to floor
	char3->equip(m3);
	char3->unequip(0); // m3 goes to floor

	std::cout << "\nDEMONSTRATING CHARACTER TRACKING IMPORTANCE:\n";
	std::cout << "1. All materias are currently on the floor:\n";
	Character::printFloorMaterias(); // Show initial floor state

	// Without proper tracking, deleting any character would clear the floor!
	delete char1; // Should NOT clean floor with proper tracking
	std::cout << "\nFirst character deleted, floor materias should still be accessible:\n";
	Character::printFloorMaterias(); // Should still show materias if tracking works

	delete char2; // Should NOT clean floor with proper tracking
	std::cout << "\nSecond character deleted, floor materias should still be accessible:\n";
	Character::printFloorMaterias(); // Should still show materias if tracking works

	std::cout << "\nDeleting last character will clean up all floor materias...\n";
	delete char3; // Should clean floor (last character)
	std::cout << "Last character deleted, floor materias cleaned up:\n";
	Character::printFloorMaterias(); // Should show empty floor

	// At this point, all floor materias have been properly cleaned up
	// If we didn't track the last character, we'd have memory leaks

	delete src;

	return 0;
}
