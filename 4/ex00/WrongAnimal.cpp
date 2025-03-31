/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:50 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:16:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("none") { std::cout << "WrongAnimal default constructor called" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		setType(other.getType());
	}
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal destructor called" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) {}

std::string WrongAnimal::getType() const
{
	return this->_type;
}

void WrongAnimal::setType(std::string new_type)
{
	this->_type = new_type;
}

void WrongAnimal::makeSound() const { std::cout << "WrongAnimal sound" << std::endl; }
