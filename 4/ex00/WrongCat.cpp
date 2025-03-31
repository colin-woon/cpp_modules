/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:51:55 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/31 20:51:57 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {}

WrongCat::WrongCat(const WrongCat &other)
{
	this->value = other.value;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
	{
		this->value = other.value;
	}
	return *this;
}

WrongCat::~WrongCat() {}
