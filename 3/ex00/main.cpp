/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:08 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/03 14:27:07 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
Tests
- attack normal
- attack with no energy points
- attack with no hit points

- takeDamage normal
- takeDamage with 0 hit points
- takeDamage with damage more than hit points

- beRepaired normal
- beRepaired with 0 hit points
- beRepaired with 0 energy points
- beRepaired with amount that will cause hitpoints to exceed U_INT_MAX
*/
int main()
{
	std::cout << "\n=== Test 1: Attack normal ===" << std::endl;
	ClapTrap attacker("Attacker");
	ClapTrap target("Target");
	attacker.attack(target.getName());
	target.takeDamage(attacker.getAttackDamage());

	std::cout << "\n=== Test 2: Attack with no energy points ===" << std::endl;
	ClapTrap noEnergy("NoEnergy");
	for (int i = 0; i < 10; ++i)
	{
		noEnergy.attack("Someone");
	}
	noEnergy.attack("Someone");

	std::cout << "\n=== Test 3: Attack with no hit points ===" << std::endl;
	ClapTrap noHP("NoHP");
	noHP.takeDamage(10);
	noHP.attack("Someone");

	std::cout << "\n=== Test 4: TakeDamage normal ===" << std::endl;
	ClapTrap victim("Victim");
	victim.takeDamage(5);

	std::cout << "\n=== Test 5: TakeDamage with 0 hit points ===" << std::endl;
	ClapTrap alreadyDead("AlreadyDead");
	alreadyDead.takeDamage(10);
	alreadyDead.takeDamage(5);

	std::cout << "\n=== Test 6: TakeDamage with damage more than hit points ===" << std::endl;
	ClapTrap overkill("Overkill");
	overkill.takeDamage(15);

	std::cout << "\n=== Test 7: beRepaired normal ===" << std::endl;
	ClapTrap repairer("Repairer");
	repairer.takeDamage(5);
	repairer.beRepaired(3);

	std::cout << "\n=== Test 8: beRepaired with 0 hit points ===" << std::endl;
	ClapTrap cannotRepair("CannotRepair");
	cannotRepair.takeDamage(10);
	cannotRepair.beRepaired(5);

	std::cout << "\n=== Test 9: beRepaired with 0 energy points ===" << std::endl;
	ClapTrap noEnergyRepair("NoEnergyRepair");
	for (int i = 0; i < 10; ++i)
	{
		noEnergyRepair.attack("Someone");
	}
	noEnergyRepair.beRepaired(1);

	std::cout << "\n=== Test 10: beRepaired with amount causing overflow ===" << std::endl;
	ClapTrap overflow("Overflow");
	overflow.takeDamage(5);
	overflow.beRepaired(UINT_MAX);

	return 0;
}
