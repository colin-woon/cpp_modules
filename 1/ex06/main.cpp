/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:13:09 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/10 18:14:03 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"

int main(int ac, char **av)
{
	Harl harl;

	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Usage: ./complain [DEBUG|INFO|WARNING|ERROR]" << std::endl;
	return (0);
}
