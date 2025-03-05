/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:19:51 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
#define CONTACT_CLASS_H

#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	Contact(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickName,
			const std::string &phoneNumber,
			const std::string &darkestSecret);
	~Contact(void);

	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhoneNumber(void) const;
	std::string getDarkestSecret(void) const;

	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickName(const std::string &nickName);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);
};

#endif
