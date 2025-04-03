/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:00:15 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/03 16:00:17 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() { std::cout << "Unnamed is type FragTrap." << std::endl; }

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << other.getName() << "!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap assignment operator called for " << other.getName() << "!" << std::endl;
	}
	return *this;
}

FragTrap::~FragTrap() { std::cout << "FragTrap is destroyed" << std::endl; }

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100)
{
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << name << " is type FragTrap" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->getName() << " requests a high five!" << std::endl;
}

unsigned int FragTrap::getDefaultAttackDamage() const { return 30; }
unsigned int FragTrap::getDefaultHitPoints() const { return 100; }
