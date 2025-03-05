/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:55:39 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/05 16:32:47 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

void searchContact();
void addNewContact(PhoneBook &phoneBook);

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

		if (input == "EXIT" || std::cin.eof() || std::cin.fail())
		{
			std::cout << "Exiting program..." << std::endl;
			return (0);
		}
		else if (input == "SEARCH")
			searchContact();
		else if (input == "ADD")
		{
			addNewContact(phoneBook);
			continue;
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
		while (true)
		{
			std::cin >> input[i];

			if (input->empty())
				std::cout << "Field must not be empty. Please enter something." << std::endl;
			else
				break;
		}
	}

	Contact newContact(input[0], input[1], input[2], input[3], input[4]);
	phoneBook.appendContact(newContact);
}

void searchContact()
{
}
