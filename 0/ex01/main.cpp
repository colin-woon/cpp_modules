/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:39 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 20:40:39 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <iomanip>
#include <cstdlib>

void addNewContact(PhoneBook &phoneBook);
void searchContact(PhoneBook &phoneBook);
void viewPhoneBook(PhoneBook &phoneBook);
std::string truncateString(std::string str);
void searchContactByIndex(PhoneBook &phoneBook);

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

		while (true)
		{
			std::cin >> input;
			std::cout << std::endl;
			if (input == "EXIT" || std::cin.eof() || std::cin.fail())
			{
				std::cout << "Exiting program..." << std::endl;
				return (0);
			}
			else if (input == "SEARCH")
			{
				searchContact(phoneBook);
				break;
			}
			else if (input == "ADD")
			{
				addNewContact(phoneBook);
				break;
			}
			else
				std::cout << "Invalid command. Please try again." << std::endl;
		}
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
	if (phoneBook.getNbOfContacts() == 0)
	{
		std::cout << "[No contacts available]" << std::endl
				  << std::endl;
		return;
	}
	viewPhoneBook(phoneBook);
	std::cout << "Enter the index of the contact you want to view: (Enter 0 to go back)" << std::endl;
	searchContactByIndex(phoneBook);
}

void viewPhoneBook(PhoneBook &phoneBook)
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
	std::cout << std::endl;
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

void searchContactByIndex(PhoneBook &phoneBook)
{
	std::string input;
	int num;

	while (true)
	{
		std::cin >> input;
		if (input == "0")
		{
			std::cout << "Going Back..." << std::endl
					  << std::endl;
			return;
		}
		num = atoi(input.c_str());
		if (num > 0 && num <= phoneBook.getNbOfContacts())
		{
			phoneBook.getContact(num - 1).printDetails();
			break;
		}
		else
			std::cout << "Invalid index. Please try again." << std::endl;
	}
}
