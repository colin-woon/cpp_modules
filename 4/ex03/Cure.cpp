/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:10:35 by cwoon             #+#    #+#             */
/*   Updated: 2025/04/01 20:28:01 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	(void)other;
	// std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	(void)other; // unused parameter since we don't copy anything
	return *this;
}

Cure::~Cure()
{
	// std::cout << "Cure destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	// std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
