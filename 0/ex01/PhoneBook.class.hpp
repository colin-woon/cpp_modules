/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:54:10 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:20:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
#define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

class PhoneBook
{
private:
	Contact contacts[8];

public:
	PhoneBook();
	~PhoneBook(void);
	void appendContact(Contact newContact);
};

#endif
