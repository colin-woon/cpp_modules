/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:05:41 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/13 20:09:32 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level)
{
	enum Level
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int logLevel = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			logLevel = i;
			break;
		}
	}
	switch (logLevel)
	{
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case DEBUG:
		this->debug();
	case INFO:
		this->info();
	case WARNING:
		this->warning();
	case ERROR:
		this->error();
	}
}
