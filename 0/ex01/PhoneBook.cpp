/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:55:49 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:20:53 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

// Contact PhoneBook::contacts[8];
PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::appendContact(Contact newContact)
{
	this->contacts[0] = newContact;
	std::cout << this->contacts[0].getFirstName() << std::endl;
}
