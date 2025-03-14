/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:49:45 by cwoon             #+#    #+#             */
/*   Updated: 2025/03/14 16:49:29 by cwoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}

// int main(void)
// {
// 	// Test constructors
// 	Fixed a(10.5f);
// 	Fixed b(5.25f);
// 	Fixed c;

// 	// Test arithmetic operators
// 	std::cout << "--- Arithmetic Operators ---" << std::endl;
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "a + b = " << (a + b) << std::endl;
// 	std::cout << "a - b = " << (a - b) << std::endl;
// 	std::cout << "a * b = " << (a * b) << std::endl;
// 	std::cout << "a / b = " << (a / b) << std::endl;

// 	// Test comparison operators
// 	std::cout << "\n--- Comparison Operators ---" << std::endl;
// 	std::cout << "a > b: " << (a > b) << std::endl;
// 	std::cout << "a < b: " << (a < b) << std::endl;
// 	std::cout << "a >= b: " << (a >= b) << std::endl;
// 	std::cout << "a <= b: " << (a <= b) << std::endl;
// 	std::cout << "a == b: " << (a == b) << std::endl;
// 	std::cout << "a != b: " << (a != b) << std::endl;

// 	// Test increment/decrement
// 	std::cout << "\n--- Increment/Decrement ---" << std::endl;
// 	c = a;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "++c = " << ++c << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "c++ = " << c++ << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "--c = " << --c << std::endl;
// 	std::cout << "c = " << c << std::endl;
// 	std::cout << "c-- = " << c-- << std::endl;
// 	std::cout << "c = " << c << std::endl;

// 	// Test min/max functions
// 	std::cout << "\n--- Min/Max Functions ---" << std::endl;
// 	std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
// 	std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;

// 	// Test const min/max
// 	const Fixed d(15.75f);
// 	const Fixed e(7.25f);
// 	std::cout << "const min(d,e) = " << Fixed::min(d, e) << std::endl;
// 	std::cout << "const max(d,e) = " << Fixed::max(d, e) << std::endl;

// 	Fixed i;

// 	i++;
// 	std::cout << "I IS " << i << std::endl;
// 	// i--;
// 	// std::cout << "I IS " << i << std::endl;
// 	while (i-- > 0)
// 	{
// 		std::cout << "looping i " << i << std::endl;
// 		i--;
// 	}

// 	Fixed x(8388607);
// 	Fixed y(8388607);
// 	// Fixed x(8388607);
// 	// Fixed y(0.003f);

// 	std::cout << x / y << std::endl;

// 	return 0;
// }
