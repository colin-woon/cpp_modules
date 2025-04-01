/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:02:34 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 18:30:28 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""), _inventoryCount(0), _inventory() { std::cout << "Character default constructor called" << std::endl; }

Character::Character(const Character &other) : _name(other.getName()), _inventoryCount(other.getInventoryCount())
{
	for (int i = 0; i < 4; i++)
	{
		if (other.getMateria(i))
			this->_inventory[i] = other.getMateria(i)->clone();
		else
			this->_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		this->_inventoryCount = other.getInventoryCount();
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other.getMateria(i))
				this->_inventory[i] = other.getMateria(i)->clone();
			else
				this->_inventory[i] = NULL;
		}
		std::cout << "Character assignment operator called" << std::endl;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character::Character(std::string name) : _name(name), _inventoryCount(0), _inventory()
{
	std::cout << "Character parameterized constructor called" << std::endl;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (m && _inventoryCount < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] == NULL)
			{
				_inventory[i] = m;
				increaseInventoryCount();
				std::cout << "Equipped " << m->getType() << " in slot " << i << std::endl;
				return;
			}
		}
	}
	else
		std::cout << "Cannot equip " << m->getType() << ": Inventory is full or materia is not found" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
	{
		std::cout << "Unequipped " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
		_inventory[idx] = NULL;
		decreaseInventoryCount();
	}
	else
		std::cout << "Cannot unequip: Invalid index or slot is empty" << std::endl;
}

void Character::setName(std::string name)
{
	this->_name = name;
}

AMateria *Character::getMateria(int idx) const
{
	if (idx >= 0 && idx < 4)
		return _inventory[idx];
	else
		std::cout << "Invalid index" << std::endl;
	return NULL;
}

void Character::setMateria(int idx, AMateria *m)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = m;
}

void Character::printInventory() const
{
	std::cout << "Inventory of " << this->getName() << ":" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			std::cout << "Slot " << i << ": " << _inventory[i]->getType() << std::endl;
		else
			std::cout << "Slot " << i << ": empty" << std::endl;
	}
}

int Character::getInventoryCount() const
{
	return _inventoryCount;
}

void Character::increaseInventoryCount()
{
	if (_inventoryCount < 4)
		_inventoryCount++;
	else
		std::cout << "Inventory is full" << std::endl;
}

void Character::decreaseInventoryCount()
{
	if (_inventoryCount > 0)
		_inventoryCount--;
	else
		std::cout << "Inventory is empty" << std::endl;
}
