/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:39 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 20:10:11 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>

void searchContact(PhoneBook &phoneBook);
void addNewContact(PhoneBook &phoneBook);
std::string truncateString(std::string str);

int main(void)
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		std::cout << "Choose a command: " << std::endl;
		std::cout << "- ADD" << std::endl;
		std::cout << "- SEARCH" << std::endl;
		std::cout << "- EXIT" << std::endl;
		std::cin >> input;
		std::cout << std::endl;

		if (input == "EXIT" || std::cin.eof() || std::cin.fail())
		{
			std::cout << "Exiting program..." << std::endl;
			return (0);
		}
		else if (input == "SEARCH")
			searchContact(phoneBook);
		else if (input == "ADD")
			addNewContact(phoneBook);
	}
	return (0);
}

void addNewContact(PhoneBook &phoneBook)
{
	std::string input[5];
	const char *inputFields[5] = {"First Name: ",
								  "Last Name: ",
								  "Nickname: ",
								  "Phone Number: ",
								  "Darkest Secret: "};

	std::cout << "Please enter contact details: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << inputFields[i];
		std::cin >> input[i];
	}

	Contact newContact(input[0], input[1], input[2], input[3], input[4]);
	phoneBook.appendContact(newContact);
	std::cout << "Contact added successfully!" << std::endl
			  << std::endl;
}

void searchContact(PhoneBook &phoneBook)
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < phoneBook.getNbOfContacts(); i++)
	{
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1;
		std::cout << "|" << std::setfill(' ') << std::setw(10) << truncateString(phoneBook.getContact(i).getFirstName());
		std::cout << "|" << std::setfill(' ') << std::setw(10) << truncateString(phoneBook.getContact(i).getLastName());
		std::cout << "|" << std::setfill(' ') << std::setw(10) << truncateString(phoneBook.getContact(i).getNickName()) << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

std::string truncateString(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	return (str);
}
