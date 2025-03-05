/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:49 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 18:33:46 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook(void) {}

int PhoneBook::_index = 0;

void PhoneBook::appendContact(Contact newContact)
{
	if (getIndex() == get_maxContacts())
		resetIndex();
	setContact(newContact);
	incrementIndex();
}

void PhoneBook::displayContacts(void) const
{
	for (int i = 0; i < getIndex(); i++)
	{
		std::cout << "Contact " << i + 1 << std::endl;
		contacts[i].printDetails();
	}
}

int PhoneBook::get_maxContacts(void) const { return this->_maxContacts; }

int PhoneBook::getIndex(void) const { return this->_index; }
void PhoneBook::resetIndex(void) { this->_index = 0; }
void PhoneBook::incrementIndex(void) { this->_index++; }

void PhoneBook::setContact(Contact newContact) { this->contacts[getIndex()] = newContact; }
