/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:05:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("none") { std::cout << "AAnimal default constructor called" << std::endl; }

AAnimal::AAnimal(const AAnimal &other) : _type(other._type) {}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
	{
		setType(other.getType());
	}
	return *this;
}

AAnimal::~AAnimal() { std::cout << "AAnimal destructor called" << std::endl; }

AAnimal::AAnimal(std::string type) : _type(type) {}

std::string AAnimal::getType() const
{
	return this->_type;
}

void AAnimal::setType(std::string new_type)
{
	this->_type = new_type;
}
