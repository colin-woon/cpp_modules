/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:58:19 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/04 16:08:50 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _storage(), _storageCount(0)
{
	// std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other) : _storageCount(other.getStorageCount())
{
	for (int i = 0; i < _storageCount; i++)
	{
		if (other.getMateria(i))
			this->_storage[i] = other.getMateria(i)->clone();
		else
			this->_storage[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	for (int i = 0; i < _storageCount; i++)
	{
		if (this->_storage[i])
			delete this->_storage[i];
		if (other.getMateria(i))
			this->_storage[i] = other.getMateria(i)->clone();
		else
			this->_storage[i] = NULL;
	}
	this->_storageCount = other.getStorageCount();
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _storageCount; i++)
	{
		if (_storage[i])
			delete _storage[i];
	}
	_storageCount = 0;
	// std::cout << "MateriaSource destructor called" << std::endl;
}

AMateria *MateriaSource::getMateria(int index) const
{
	if (index < 0 || index >= _storageCount)
		return NULL;
	return this->_storage[index];
}

int MateriaSource::getStorageCount() const
{
	return this->_storageCount;
}

void MateriaSource::incrementStorageCount()
{
	if (this->_storageCount < 4)
		this->_storageCount++;
	else
		std::cout << "MateriaSource storage is full" << std::endl;
}

void MateriaSource::decrementStorageCount()
{
	if (this->_storageCount > 0)
		this->_storageCount--;
	else
		std::cout << "MateriaSource storage is empty" << std::endl;
}

/**
 * @brief Learns a new Materia by storing its clone in source's storage
 *
 * @param m Pointer to AMateria to learn (will be deleted)
 *
 * @note Storage limited to 4 Materias
 * @note Original Materia is deleted after cloning
 * @warning DO NOT use this pattern:
 *    AMateria* ice = new Ice();
 *    materia_source.learnMateria(ice);
 *    delete ice;  // WRONG: Double deletion, ice is already deleted in learnMateria
 *
 * Example of correct usage:
 *    src->learnMateria(new Ice());  // Ice cloned and original deleted
 */

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	if (this->_storageCount < 4)
	{
		this->_storage[this->_storageCount] = m->clone();
		delete m;
		this->incrementStorageCount();
	}
	else
	{
		delete m;
		std::cout << "MateriaSource storage is full" << std::endl;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_storageCount; i++)
	{
		if (this->_storage[i]->getType() == type)
			return this->_storage[i]->clone();
	}
	return NULL;
}
