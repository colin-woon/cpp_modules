/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:10:32 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 17:47:37 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") { std::cout << "Ice default constructor called" << std::endl; }

Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other; // unused parameter since we don't copy anything
	return *this;
}

Ice::~Ice() { std::cout << "Ice destructor called" << std::endl; }

AMateria *Ice::clone() const
{
	std::cout << "Ice clone called" << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
