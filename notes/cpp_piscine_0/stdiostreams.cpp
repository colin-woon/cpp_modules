/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdiostreams.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:06:16 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/03 15:07:10 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	char buff[500];

	std::cout << "Hello World!" << std::endl;
	std::cout << "Input(not more than 500 char): ";
	std::cin >> buff;
	std::cout << "You entered: " << buff << std::endl;
}
