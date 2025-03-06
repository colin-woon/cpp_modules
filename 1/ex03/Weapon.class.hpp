/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:23:44 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 20:53:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP

#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type);
	~Weapon();
	std::string const &getType();
	void setType(std::string type);
};

#endif
