/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:49 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:52:00 by cwoon            ###   ########.fr       */
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

int PhoneBook::get_maxContacts() const { return this->_maxContacts; }

int PhoneBook::getIndex() const { return this->_index; }
void PhoneBook::resetIndex() { this->_index = 0; }
void PhoneBook::incrementIndex() { this->_index++; }

void PhoneBook::setContact(Contact newContact) { this->contacts[getIndex()] = newContact; }
