/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:55 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 21:18:19 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") { std::cout << "WrongCat default constructor called" << std::endl; }

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
