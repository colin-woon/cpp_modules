/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:59:46 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/03 15:38:53 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() { std::cout << "Unnamed is type ScavTrap." << std::endl; }

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << other.getName() << "!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "ScavTrap assignment operator called for " << other.getName() << "!" << std::endl;
	}
	return *this;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap is destroyed" << std::endl; }

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100)
{
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
	std::cout << name << " is type ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ScavTrap " << this->getName() << " has no energy points left to attack!" << std::endl;
		return;
	}
	this->useEnergyPoints();
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << this->getName() << " has entered in Gate keeper mode." << std::endl;
}

unsigned int ScavTrap::getDefaultEnergyPoints() const { return 50; }
