/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:23:44 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/13 19:57:39 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
#define WEAPON_CLASS_HPP

#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();
	std::string const &getType();
	void setType(std::string type);
};

#endif
