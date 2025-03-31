/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:41 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:05:31 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") { std::cout << "Dog default constructor called" << std::endl; }

Dog::Dog(const Dog &other) : Animal(other) {}

Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog::Dog(std::string type) : Animal(type) {}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}
