/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:00:05 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/03 16:27:31 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// The Construction Order: Base Before Derived
// the construction process always starts with the base class(es) and proceeds towards the derived class.
// This is because the derived class object contains the base class object(s),
// and the base class part must be initialized before the derived class can build upon it.
DiamondTrap::DiamondTrap() : ClapTrap("_clap_name", 100), ScavTrap(), FragTrap(), _name("")
{
	std::cout << "Unnamed is type DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.getName() + "_clap_name", 100), ScavTrap(other), FragTrap(other), _name(other.getName())
{
	setHitPoints(other.getHitPoints());
	setEnergyPoints(other.getEnergyPoints());
	setAttackDamage(other.getAttackDamage());
	std::cout << "DiamondTrap copy constructor called for " << other.getName() << "!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other.getName();
		std::cout << "DiamondTrap assignment operator called for " << other.getName() << "!" << std::endl;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap is destroyed" << std::endl; }

std::string DiamondTrap::getName() const { return _name; }

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name", 100), ScavTrap(name), FragTrap(name), _name(name)
{
	this->setHitPoints(FragTrap::getDefaultHitPoints());
	this->setEnergyPoints(ScavTrap::getDefaultEnergyPoints());
	this->setAttackDamage(FragTrap::getDefaultAttackDamage());
	std::cout << this->getName() << " is type DiamondTrap" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << this->getName() << " and ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
