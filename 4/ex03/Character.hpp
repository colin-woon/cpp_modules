/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:53:20 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 18:21:12 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];
	int _inventoryCount;

public:
	Character();
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	Character(std::string name);
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

	void setName(std::string name);
	AMateria *getMateria(int idx) const;
	void setMateria(int idx, AMateria *m);
	void printInventory() const;
	int getInventoryCount() const;
	void increaseInventoryCount();
	void decreaseInventoryCount();
};

#endif
