/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:41 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 22:37:56 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) { std::cout << "Dog default constructor called" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {}

// Dog::Dog(const Dog &other) : Animal(other)
// {
// 	// Shallow copy - both objects will point to the same Brain!
// 	this->_brain = other._brain;
// }

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), _brain(new Brain()) {}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
