/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:10 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 19:36:40 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
private:
	static const int _maxContacts = 8;
	static int _nbOfContacts;
	static int _index;
	Contact contacts[_maxContacts];

public:
	PhoneBook();
	~PhoneBook(void);

	int get_maxContacts(void) const;

	int getNbOfContacts(void) const;
	void incrementNbOfContacts(void);

	int getIndex(void) const;
	void incrementIndex(void);
	void resetIndex(void);

	Contact getContact(int index) const;
	void setContact(Contact newContact);
	void appendContact(Contact newContact);
	void displayContacts(void) const;
};

#endif
