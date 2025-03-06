/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:23:35 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 21:08:30 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.class.hpp"

/*
since weapon is a reference, which is const,
cannot initialize with this->weapon = weapon
*/
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
