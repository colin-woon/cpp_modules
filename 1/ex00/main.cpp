/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:05:58 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/06 17:55:05 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

/*
sam is stored on the heap,
so even if the function that created him finished, it still exists

joe is stored on the stack,
so after the function that created him finished, it is destroyed
*/
int main()
{
	Zombie *sam = newZombie("sam");
	sam->announce();
	randomChump("joe");
	delete sam;
	return 0;
}
