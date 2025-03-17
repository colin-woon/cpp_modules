/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:08 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/17 15:30:02 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

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
	// std::cout << "\n=== Test 1: Attack normal ===" << std::endl;
	// ClapTrap attacker("Attacker");
	// ClapTrap target("Target");
	// attacker.attack(target.getName());
	// target.takeDamage(attacker.getAttackDamage());

	// std::cout << "\n=== Test 2: Attack with no energy points ===" << std::endl;
	// ClapTrap noEnergy("NoEnergy");
	// for (int i = 0; i < 10; ++i)
	// {
	// 	noEnergy.attack("Someone");
	// }
	// noEnergy.attack("Someone");

	// std::cout << "\n=== Test 3: Attack with no hit points ===" << std::endl;
	// ClapTrap noHP("NoHP");
	// noHP.takeDamage(10);
	// noHP.attack("Someone");

	// std::cout << "\n=== Test 4: TakeDamage normal ===" << std::endl;
	// ClapTrap victim("Victim");
	// victim.takeDamage(5);

	// std::cout << "\n=== Test 5: TakeDamage with 0 hit points ===" << std::endl;
	// ClapTrap alreadyDead("AlreadyDead");
	// alreadyDead.takeDamage(10);
	// alreadyDead.takeDamage(5);

	// std::cout << "\n=== Test 6: TakeDamage with damage more than hit points ===" << std::endl;
	// ClapTrap overkill("Overkill");
	// overkill.takeDamage(15);

	// std::cout << "\n=== Test 7: beRepaired normal ===" << std::endl;
	// ClapTrap repairer("Repairer");
	// repairer.takeDamage(5);
	// repairer.beRepaired(3);

	// std::cout << "\n=== Test 8: beRepaired with 0 hit points ===" << std::endl;
	// ClapTrap cannotRepair("CannotRepair");
	// cannotRepair.takeDamage(10);
	// cannotRepair.beRepaired(5);

	// std::cout << "\n=== Test 9: beRepaired with 0 energy points ===" << std::endl;
	// ClapTrap noEnergyRepair("NoEnergyRepair");
	// for (int i = 0; i < 10; ++i)
	// {
	// 	noEnergyRepair.beRepaired(1);
	// }
	// noEnergyRepair.beRepaired(1);

	// std::cout << "\n=== Test 10: beRepaired with amount causing overflow ===" << std::endl;
	// ClapTrap overflow("Overflow");
	// overflow.beRepaired(UINT_MAX);

	std::cout << "\n=== ScavTrap Tests ===" << std::endl;

	std::cout << "\n=== Test 11: ScavTrap normal attack ===" << std::endl;
	ScavTrap scav_attacker("ScavAttacker");
	ScavTrap scav_target("ScavTarget");
	scav_attacker.attack(scav_target.getName());
	scav_target.takeDamage(scav_attacker.getAttackDamage());

	std::cout << "\n=== Test 12: ScavTrap Guard Gate ===" << std::endl;
	scav_attacker.guardGate();

	std::cout << "\n=== Test 13: ScavTrap energy points depletion ===" << std::endl;
	ScavTrap scav_maxAttacks("ScavAttacker");
	for (int i = 0; i < 50; ++i)
	{
		scav_maxAttacks.attack("Someone");
		std::cout << "Energy points: " << scav_maxAttacks.getEnergyPoints() << std::endl;
	}
	scav_maxAttacks.attack("Someone"); // Should fail - no energy points

	std::cout << "\n=== Test 14: ScavTrap high HP test ===" << std::endl;
	ScavTrap tank("Tank");
	std::cout << "Initial HP: " << tank.getHitPoints() << std::endl;
	tank.takeDamage(50);
	std::cout << "After 50 damage: " << tank.getHitPoints() << std::endl;
	tank.takeDamage(50);
	tank.attack("Someone"); // Should fail - no hit points
	tank.beRepaired(50);	// Should fail - no hit points

	std::cout << "\n=== Test 15: ScavTrap copy constructor test ===" << std::endl;
	ScavTrap original("Original");
	ScavTrap copy(original);
	copy.attack("Target");
	copy.guardGate();

	return 0;
}
