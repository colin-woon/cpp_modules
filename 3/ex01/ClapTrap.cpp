/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:13 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/17 15:30:52 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Unnamed ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	this->setName(other.getName());
	this->setHitPoints(other.getHitPoints());
	this->setEnergyPoints(other.getEnergyPoints());
	this->setAttackDamage(other.getAttackDamage());
	std::cout << "ClapTrap copy constructor called for " << other.getName() << "!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	std::cout << "ClapTrap assignment operator called for " << other.getName() << "!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap is destroyed" << std::endl; }

std::string ClapTrap::getName() const { return this->_name; }
unsigned int ClapTrap::getAttackDamage() const { return this->_attackDamage; }
unsigned int ClapTrap::getHitPoints() const { return this->_hitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return this->_energyPoints; }

void ClapTrap::setName(const std::string &name) { this->_name = name; }
void ClapTrap::setHitPoints(unsigned int hitPoints) { this->_hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(unsigned int energyPoints) { this->_energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(unsigned int attackDamage) { this->_attackDamage = attackDamage; }

void ClapTrap::useEnergyPoints()
{
	if (getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy points left!" << std::endl;
		return;
	}
	this->_energyPoints -= 1;
}

void ClapTrap::reduceHitPoints(unsigned int damageAmount)
{
	if (this->getHitPoints() < damageAmount)
		setHitPoints(0);
	else
		this->_hitPoints -= damageAmount;
}

void ClapTrap::increaseHitPoints(unsigned int repairAmount)
{
	if (UINT_MAX - this->getHitPoints() < repairAmount)
	{
		std::cout << "Repairing " << this->getName() << " for " << repairAmount << " HP would cause an overflow error!" << std::endl;
		return;
	}
	this->_hitPoints += repairAmount;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->getName() << " is created" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy points left to attack!" << std::endl;
		return;
	}
	if (this->getHitPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead and cannot attack!" << std::endl;
		return;
	}
	this->useEnergyPoints();
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is already dead." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
	reduceHitPoints(amount);
	if (this->getHitPoints() == 0)
		std::cout << "ClapTrap " << this->getName() << " is dead." << std::endl;
	else
		std::cout << "ClapTrap " << this->getName() << " now has " << this->getHitPoints() << " hit points left." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " is dead and cannot be repaired." << std::endl;
		return;
	}
	if (this->getEnergyPoints() == 0)
	{
		std::cout << "ClapTrap " << this->getName() << " has no energy points left to repair itself!" << std::endl;
		return;
	}
	if (UINT_MAX - this->getHitPoints() < amount)
	{
		std::cout << "Repairing " << this->getName() << " for " << amount << " HP would cause an overflow!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->getName() << " is repaired for " << amount << " points!" << std::endl;
	this->increaseHitPoints(amount);
	this->useEnergyPoints();
	std::cout << "ClapTrap " << this->getName() << " now has " << this->getHitPoints() << " hit points left." << std::endl;
}
