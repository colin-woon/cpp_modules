/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:21 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:05:26 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") { std::cout << "Cat default constructor called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {}

Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(std::string type) : Animal(type) {}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
