/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:10 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 18:31:52 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
private:
	static const int _maxContacts = 8;
	Contact contacts[_maxContacts];
	static int _index;

public:
	PhoneBook();
	~PhoneBook(void);

	int get_maxContacts(void) const;

	int getIndex(void) const;
	void incrementIndex(void);
	void resetIndex(void);

	void setContact(Contact newContact);
	void appendContact(Contact newContact);
	void displayContacts(void) const;
};

#endif
