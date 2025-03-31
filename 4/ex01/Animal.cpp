/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:05:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("none") { std::cout << "Animal default constructor called" << std::endl; }

Animal::Animal(const Animal &other) : _type(other._type) {}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		setType(other.getType());
	}
	return *this;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(std::string type) : _type(type) {}

std::string Animal::getType() const
{
	return this->_type;
}

void Animal::setType(std::string new_type)
{
	this->_type = new_type;
}

void Animal::makeSound() const { std::cout << "Animal sound" << std::endl; }
