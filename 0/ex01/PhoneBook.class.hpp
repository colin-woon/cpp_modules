/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:10 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:50:46 by cwoon            ###   ########.fr       */
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
	void appendContact(Contact newContact);
	int get_maxContacts() const;
	int getIndex() const;
	void incrementIndex();
	void resetIndex();
	// Contact getContact() const;
	void setContact(Contact newContact);
};

#endif
