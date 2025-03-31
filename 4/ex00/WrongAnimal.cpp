/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:50 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 20:51:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->value = other.value;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {}
