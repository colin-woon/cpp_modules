/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:50:10 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/03 14:26:06 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <climits>

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
	static unsigned int const _maxHitPoints;
	static unsigned int const _maxEnergyPoints;

	void useEnergyPoints();
	void reduceHitPoints(unsigned int damageAmount);
	void increaseHitPoints(unsigned int repairAmount);

public:
	ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	std::string getName() const;
	unsigned int getAttackDamage() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;

	ClapTrap(const std::string &name);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
