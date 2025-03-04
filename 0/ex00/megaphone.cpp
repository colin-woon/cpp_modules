/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:55:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/04 17:50:22 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	(void)ac;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; av[j]; j++)
	{
		for (int i = 0; av[j][i]; i++)
			std::cout << (char)std::toupper(av[j][i]);
	}
	std::cout << std::endl;
}
