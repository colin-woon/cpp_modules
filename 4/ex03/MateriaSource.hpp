/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:57:23 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 20:09:35 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource
{
private:
	AMateria *_storage[4];
	int _storageCount;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	AMateria *getMateria(int index) const;
	int getStorageCount() const;
	void incrementStorageCount();
	void decrementStorageCount();

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif
