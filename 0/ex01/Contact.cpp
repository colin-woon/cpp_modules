/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:08:13 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 20:36:21 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}

Contact::Contact(const std::string &firstName,
				 const std::string &lastName,
				 const std::string &nickName,
				 const std::string &phoneNumber,
				 const std::string &darkestSecret)
	: _firstName(firstName),
	  _lastName(lastName),
	  _nickName(nickName),
	  _phoneNumber(phoneNumber),
	  _darkestSecret(darkestSecret)
{
	if (firstName.empty() || lastName.empty() || nickName.empty() ||
		phoneNumber.empty() || darkestSecret.empty())
	{
		throw std::invalid_argument("All fields must have a value");
	}
}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const { return this->_firstName; }
std::string Contact::getLastName(void) const { return this->_lastName; }
std::string Contact::getNickName(void) const { return this->_nickName; }
std::string Contact::getPhoneNumber(void) const { return this->_phoneNumber; }
std::string Contact::getDarkestSecret(void) const { return this->_darkestSecret; }

void Contact::setFirstName(const std::string &firstName) { _firstName = firstName; }
void Contact::setLastName(const std::string &lastName) { _lastName = lastName; }
void Contact::setNickName(const std::string &nickName) { _nickName = nickName; }
void Contact::setPhoneNumber(const std::string &phoneNumber) { _phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(const std::string &darkestSecret) { _darkestSecret = darkestSecret; }

void Contact::printDetails(void) const
{
	std::cout << std::endl;
	std::cout << "First Name: " << this->getFirstName() << std::endl;
	std::cout << "Last Name: " << this->getLastName() << std::endl;
	std::cout << "Nickname: " << this->getNickName() << std::endl;
	std::cout << "Phone Number: " << this->getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->getDarkestSecret() << std::endl;
	std::cout << std::endl;
}
