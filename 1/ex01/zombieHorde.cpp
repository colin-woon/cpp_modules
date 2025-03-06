/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:01:49 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 20:05:38 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

/*
cant use zombies[i] = Zombie("Bob"); as it will create a temporary object
and assign it to zombies[i] which will be destroyed after the statement
 */
Zombie *zombieHorde(int N, std::string new_name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombies[i].setName(new_name);
	return zombies;
}
